/*
  Распиновка изделия:

  [MEGA 2560]
  Секция ПИТАНИЕ
    +5V                   VIN<-TP4056
    GND                   GND<-TP4056
    Capacitor             +5V -||- GND

  Секция ФИЛЬТРЫ
    Мишени (1.1 MOhm)
      Мишень 1            A0 -[=]- GND
      Мишень 2            A1 -[=]- GND
      Мишень 3            A2 -[=]- GND
      Мишень 4            A3 -[=]- GND
      Мишень 5            A4 -[=]- GND
      Мишень 6            A5 -[=]- GND
  
  Секция МИШЕНИ
    RGB Шина
      Красный             D6
      Зелёный             D5
      Синий               D4
    Контроль подсветки:
      Мишень 1            D22
      Мишень 2            D23
      Мишень 3            D24
      Мишень 4            D26
      Мишень 5            D25
      Мишень 6            D27
    Считывание сигнала:
      Мишень 1            A0
      Мишень 2            A1
      Мишень 3            A2
      Мишень 4            A3
      Мишень 5            A4
      Мишень 6            A5
      
  Cекция ЛЕНТЫ
    Шина SPI База         D52
    Шина SPI Рёбра        D51
    Шина SPI Шпиль        D50
    
  Секция ВНЕШНИЕ УСТРОЙСТВА
    Сопроцессор Nano      RX1<->TX0
                          TX1<->RX0
    Сигнал уровня заряда  A8

  [NANO 328P]

  [МИШЕНЬ]
  КТ3102АМ
    Эмиттер               Общий анод RGB
    База + 100 Ohm        Контроль подсветки
    Коллектор             +5V
  RGB Светодиоды
    R + 220 Ohm           R Шина
    Общий анод            Эмиттер
    G + 220 Ohm           G Шина
    B + 220 Ohm           B Шина
  Пьезоэлемент
    Сигнал                Считывание сигнала
    Общий                 GND
*/

// Отключает санитайзер кода. Крайне не рекомендуется
// использовать, только в случае уверенности в себе,
// своём коде и заданной конфигурации!
//#define DISABLE_SECURE_COMPILING

// Выбор целевой платформы. Выбрать только одну!
// Компилировать для ЯДРА. Параметры программатора:
// Плата:           Arduino Mega or Mega 2560
// Процессор:       ATmega2560 (Mega 2560)
// Программатор:    Arduino as ISP (или AVRISP mkII)
#define COMPILE_FOR_MEGA2560
// Компилировать для СОПРОЦЕССОРА. Параметры программатора:
// Плата:           Arduino Nano
// Процессор:       ATmega328P (Old Bootloader)
// Программатор:    AVRISP mkII
//#define COMPILE_FOR_NANO328P

// Аппаратные константы. Смотри распиновку (сверху) и описание
// классов (DNKCore.h)
#define RGBD_CHANNELS     3
#define RED_PWMC          6
#define GRN_PWMC          5
#define BLU_PWMC          4
// Пины мишеней (управление подсветкой):
#define TARGET_1          22
#define TARGET_2          23
#define TARGET_3          24
#define TARGET_4          26
#define TARGET_5          25
#define TARGET_6          27
// Аналоговые пины мишеней (сигнал):
#define TARGET_SIGN_1     A1
#define TARGET_SIGN_2     A2
#define TARGET_SIGN_3     A3
#define TARGET_SIGN_4     A4
#define TARGET_SIGN_5     A5
#define TARGET_SIGN_6     A6
// Пины ленты (SPI)
#define PIN_NUM_BASE      52
#define PIN_NUM_SIDE_1    51
#define PIN_NUM_SIDE_2    50

// Программные константы
// Граница чувствительности пьезодатчиков
#define HIT_THRESHOLD_T1  1000
#define HIT_THRESHOLD_T2  1000
#define HIT_THRESHOLD_T3  1000
#define HIT_THRESHOLD_T4  1000
#define HIT_THRESHOLD_T5  1000
#define HIT_THRESHOLD_T6  1000
// Начальное количество хп
#define HP_VALUE          100
// коэффициент деления для перевода количества хп в цвет
// (с дефолтными значениями здоровья и коэфа цвета меняются с зеленого на красный)
#define HP_DIV            330
// Стартовое значение цвета здоровья башни:
#define HP_COLOR          0.3
// урон
#define DAMAGE            2
// количество морганий мишени при попадании
#define BLINK_ITERATOR    10
// Частота мерцаний мишени при хите
#define BLINK_FREQUENCY   200
// Задержки:
// Задержка моргания мишеней:
#define DELAY_TARGET      20
// Задержка первой анимации базы:
#define DELAY_BASE_1      25
// Задержка второй анимации базы:
#define DELAY_BASE_2      25
// Задержка анимации боковых ребер:
#define DELAY_SIDE        10
// Задержка анимации потухания:
#define DELAY_OFF         25
