#pragma once

//#ifdef COMPILE_FOR_MEGA2560

#include <Arduino.h>
#include "LEDStrip.h"
#include "RGBDiode.h"
#include "HSL.h"
#include "Definitions.h"

/*
  Реализация класса башни. Каждая секция содержит в себе конкретный вид
  данных:
    objects - объекты классов
    constants - константы
    variables - переменные
    arrays - массивы
    methods - методы
    setters - установщики
    getters - передатчики
    events - события

  Секция объектов:
    strip - интерфейс светодиодных лент
    bus - объект RGB шины
    converter - объект конвертера цветов HSL->RGB

  Секция констант:
    _hitThreshold - чувствительность датчиков

  Секция переменных:
    hitPoints - хитпоинты башни
    hpColor - текущий цвет башни

  Секция массивов:
    targetPins - пины датчиков мишеней
    targetLights - пины контроля подсветки мишеней

  Секция методов:
    towerInit() - стартовая настройка башни
    towerCycle() - цикличные операции башни

  Секция установщиков:
    setHPColor() - обновляет цвет башни

  Секция передатчиков:
    getHittedTarget() - возвращает данные от мишеней

  Секция событий:
    onTargetHitEvent() - событие попадания по любой
                         из мишеней
    onTowerDestroyedEvent() - событие уничтожения башни
*/
class Tower
{
private:
    // @section objects
    LEDstrip          strip;
    RGBDiode* bus;
    HSL* converter;

    // @section constants
    const int         _hitThreshold = HIT_THRESHOLD;

    // @section variables
    double            hitPoints;
    double            hpColor;

    // @section arrays
    byte* targetPins;
    byte* targetLight;

    // @section methods
    void              towerInit();
    void              towerCycle();

    // @section setters
    void              setHPColor();

    // @section getters
    byte              getHittedTarget();

    // @section events
    void              onTargetHitEvent(byte);
    void              onTowerDestroyedEvent();

    // @section delegates
    void              callCoProcessor(byte*);
    void              resetCoProcessor();
public:
    Tower();
    ~Tower();
};

//#endif