#include "headers/CoProcessor.h"
#include "headers/DNKCore.h"


#ifdef COMPILE_FOR_NANO328P

CoProcessor::~CoProcessor()
{
	memset(this, NULL, sizeof(*this));
}

CoProcessor::CoProcessor()
{
	pinData = new byte[8]
	{
		INTERRUPT_PIN,
		TARGET_LIGHT_1,
		TARGET_LIGHT_2,
		TARGET_LIGHT_3,
		TARGET_LIGHT_4,
		TARGET_LIGHT_5,
		TARGET_LIGHT_6,
		SOUND_PIN
	};
	processorInit();
	for (;;)
	{
		// some interrupt there
		processorCycle();
	}
}

void CoProcessor::processorInit()
{
	Serial.begin(74880);
	pinMode(pinData[PinInterrupt], INPUT_PULLUP);
	attachInterrupt(0, onResetEvent, RISING);
}

void CoProcessor::processorCycle()
{
	if (Serial.available())
		SquareWave(pinData[PinSound], Serial.read(), 25, true);
}

void CoProcessor::onResetEvent()
{
	for (byte i(PinInterrupt); i < PinSound; i++)
		digitalWrite(pinData[i], LOW);
}

#endif