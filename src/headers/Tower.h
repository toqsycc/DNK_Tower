#pragma once

//#ifdef COMPILE_FOR_MEGA2560

#include <Arduino.h>
#include "LEDStrip.h"
#include "RGBDiode.h"
#include "HSL.h"
#include "Definitions.h"

/*
  ���������� ������ �����. ������ ������ �������� � ���� ���������� ���
  ������:
    objects - ������� �������
    constants - ���������
    variables - ����������
    arrays - �������
    methods - ������
    setters - �����������
    getters - �����������
    events - �������

  ������ ��������:
    strip - ��������� ������������ ����
    bus - ������ RGB ����
    converter - ������ ���������� ������ HSL->RGB

  ������ ��������:
    _hitThreshold - ���������������� ��������

  ������ ����������:
    hitPoints - ��������� �����
    hpColor - ������� ���� �����

  ������ ��������:
    targetPins - ���� �������� �������
    targetLights - ���� �������� ��������� �������

  ������ �������:
    towerInit() - ��������� ��������� �����
    towerCycle() - ��������� �������� �����

  ������ ������������:
    setHPColor() - ��������� ���� �����

  ������ ������������:
    getHittedTarget() - ���������� ������ �� �������

  ������ �������:
    onTargetHitEvent() - ������� ��������� �� �����
                         �� �������
    onTowerDestroyedEvent() - ������� ����������� �����
*/
class Tower
{
private:
    // @section objects
    LEDstrip*        strip;
    RGBDiode* bus;
    HSL* converter;

    // @section constants
    unsigned short*         _hitThreshold;

    // @section variables
    double            hitPoints;
    double            hpColor;
    bool              isTowerDestroyed;

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
    unsigned long ticker;
public:
    Tower();
    ~Tower();
};

//#endif