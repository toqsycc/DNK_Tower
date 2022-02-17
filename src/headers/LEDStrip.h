#pragma once

//#ifdef COMPILE_FOR_MEGA2560

#include <FastLED.h>
#include <Arduino.h>

/* ����� LED �����

������:
LEDstrip - �����������
activate - ��������� ���� ������������ ������������ ���� (������������ �����)
showRed - ���������������� ��������� ���� ����������� � ����� � ������� ����
showBlue - ���������������� ��������� ���� ����������� � ����� � ����� ����
showSide - ������������������ ��������� ����� �� ������� ������ ����� � ��� ����� (����� ����� ���� � ����� ������ ���� ������)
turnOff - ���������������� ���������� ���� ����������� � �����
dVal - �������� ����� �����������, � ��

��������: ����� �������������� ������� ������, ���������� ������������ ������ ����� �������� activate() */

class LEDstrip
{
private:
	CRGB leds[8];
	CRGB leds_side1[4];
	bool isReverse;
	byte currentBase;
public:
	LEDstrip();
	void activate();
	void showRed(double hue, int dVal = 100);
	void showBlue(double hue, int dVal = 100);
	void showSide(double hueStart = 0.0, double hueEnd = 0.8, int dVal = 100);
	void turnOff(int dVal = 100);
	void pushLED();
};

//#endif