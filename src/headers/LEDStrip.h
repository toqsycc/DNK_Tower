#pragma once

//#ifdef COMPILE_FOR_MEGA2560

#include <FastLED.h>
#include <Arduino.h>

/* Класс LED ленты

Методы:
LEDstrip - конструктор
activate - активация всех подключенных светодиодных лент (обязательный метод)
showRed - последовательное зажигание всех светодиодов в ленте в красный цвет
showBlue - последовательное зажигание всех светодиодов в ленте в синий цвет
showSide - последововательное зажигание ленты на боковых ребрах башни в два цвета (снизу вверх один и далее сверху вниз второй)
turnOff - последовательное отключение всех светодиодов в ленте
dVal - задержка между зажиганиями, в мс

Внимание: перед использованием методов класса, необходимо активировать объект ленты функцией activate() */

class LEDstrip
{
private:
	CRGB leds[8];
	CRGB leds_side1[4];

public:
	LEDstrip();
	void activate();
	void showRed(double hue, int dVal = 100);
	void showBlue(double hue, int dVal = 100);
	void showSide(double hueStart = 0.0, double hueEnd = 0.8, int dVal = 100);
	void turnOff(int dVal = 100);
};

//#endif