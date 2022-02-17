//#ifdef COMPILE_FOR_MEGA2560

#include "headers/Tower.h"
#include "headers/DNKCore.h"
#include "headers/Definitions.h"

Tower::~Tower()
{
  memset(this, NULL, sizeof(*this));
}

Tower::Tower() :
  hitPoints(HP_VALUE),
  hpColor(HP_COLOR)
{
  bus = new RGBDiode();
  converter = new HSL(hpColor, 1.0, 0.5);

  byte hittedTarget(0);
  targetLight = new byte[6]
  {
    TARGET_1,
    TARGET_2,
    TARGET_3,
    TARGET_4,
    TARGET_5,
    TARGET_6  
  };
  targetPins = new byte[6]
  {
    TARGET_SIGN_1,
    TARGET_SIGN_2,
    TARGET_SIGN_3,
    TARGET_SIGN_4,
    TARGET_SIGN_5,
    TARGET_SIGN_6  
  };
  
  towerInit();
  for(;;)
  {
    hittedTarget = getHittedTarget();
    if (hittedTarget)
      onTargetHitEvent(hittedTarget);
    else
      towerCycle();
  }
}

/*
  Аналог функции setup(). Я, конечно, мог её назвать так же, но
  это было бы нелогично в контексте класса. Короче, всё то же
  самое, что и setup().
*/
void Tower::towerInit()
{
  Serial.begin(19200);
  Serial1.begin(74880);
  strip.activate();
  
  for (byte i(0); i < 6; i++)
  {
    byte currentPin = this->targetLight[i];
    pinMode(currentPin, OUTPUT);
    digitalWrite(currentPin, HIGH);
  }
  
  bus->SwitchColor(converter->getColorInfoRGB());
  setHPColor();

  Serial.println("Tower initialized");
}

/*
  Аналог функции loop(). Здесь можно хранить всякие неприоритетные
  задачи, как например анимации светодиодных лент, формирование
  строк фидбэка и прочие приколы.
*/
void Tower::towerCycle()
{
    //Serial.println("aboba");
}

byte Tower::getHittedTarget()
{
  byte hittedTargets(0x00);
  
  for (byte i(0); i < 6; i++)
  {
    if (analogRead(this->targetPins[i]) >= _hitThreshold)
    {
      /*
        Возвращаю линейный массив битов, соответствующий
        хитам башни:

        0b 0000 0000    | Хитов не было
        0b 0000 0001    | Хит на TARGET_SIGN_1
        0b 0000 1000    | Хит на TARGET_SIGN_4

        Соответственно, мультихит выглядит так:

        0b 0001 1001    | Хит на TARGET_SIGN_1
                                 TARGET_SIGN_4
                                 TARGET_SIGN_5
      */
      hittedTargets = hittedTargets ^ (0b1 << i);
    }
    else continue;
  }
  return hittedTargets;
}

void Tower::onTargetHitEvent(byte target)
{
  Serial1.write(target);

  byte dmgMultiplier(0);
  byte *hittedTargets = new byte[6]{ 0 };

  /*
    Обработка хитов происходит следующим образом:
      Получаем массив битов, упакованный в число target
      Конъюнктируем 0b1 с самым младшим битом target
        ИСТИНА:
          Инкрементируем множитель хитов
          Копируем пин контроля подсветкой в буферный массив
          Инкрементируем счётчик цикла
          (Опционально) Вызываем ПОСЛЕДОВАТЕЛЬНЫЙ SquareWave
            [!] Такой подход вызовет задержки, поскольку эта
            функция полностью перехватит приоритет в потоке.
        ЛОЖЬ:
          Инкрементируем счётчик цикла
      (Рекомендуется) Вызываем ПАРАЛЛЕЛЬНЫЙ SquareWave
      [!] Этот перегруженный метод позволяет создать эффект
      синхронизированности между миганиями мишени, поскольку
      сокращает задержки между зажиганиями подсветки мишеней
      от 1000 / (2 * ЧАСТОТА) миллисекунд до нескольких тактов
      (N * 0.000125 миллисекунд при ТАКТОВОЙ ЧАСТОТЕ 8 МГц)
  */
  for (byte i(0); i < 6; i++)
  {
    if (target & (0b1 << i))
    {
      hittedTargets[i] = this->targetLight[i];
      dmgMultiplier++;
      //SquareWave(this->targetLight[i], BLINK_FREQUENCY, BLINK_ITERATOR);
    }
    else continue;
  }
  
  hitPoints -= (double)(dmgMultiplier * DAMAGE);

  // Если хитпоинты закончились, то запускаем ивент уничтожения башни
  if (hitPoints <= 0.0)
    onTowerDestroyedEvent();

  // В противном случае переопределяем цвет башни и запускаем анимации
  // (Кстати, на ивентах можно реализовать стадии разрушения)

  // Не забываем отправить отладочную информацию в порт
  Serial.println(hitPoints);
  
  setHPColor();
  SquareWave(hittedTargets, BLINK_FREQUENCY, BLINK_ITERATOR);

  // Осталось только отправить пакет данных для сопроцессора
  //Serial1.write();
}

void Tower::onTowerDestroyedEvent()
{
  
}

inline void Tower::setHPColor()
{
  hpColor = hitPoints / (double)(HP_DIV);
}

//#endif