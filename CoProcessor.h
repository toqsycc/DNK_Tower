#pragma once

#include <Arduino.h>

#define INTERRUPT_PIN			2
#define TARGET_LIGHT_1			6
#define TARGET_LIGHT_2			7
#define TARGET_LIGHT_3			8
#define TARGET_LIGHT_4			9
#define TARGET_LIGHT_5			10
#define TARGET_LIGHT_6			11
#define SOUND_PIN				12

/*
  Класс сопроцессора. Содержит реализацию музыкального сопроцессора.
  Предназначен для повышения иммерсивности за счёт звуковых эффектов.
*/
class CoProcessor
{
private:
	enum PinDataEnum
	{
		PinInterrupt,
		PinTarget1,
		PinTarget2,
		PinTarget3,
		PinTarget4,
		PinTarget5,
		PinTarget6,
		PinSound
	};

	byte				*pinData;

	void                processorInit();
	void                processorCycle();
	void				onResetEvent();
public:
	CoProcessor();
	~CoProcessor();
};