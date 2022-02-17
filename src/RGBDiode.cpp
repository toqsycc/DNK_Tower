//#ifdef COMPILE_FOR_MEGA2560

#include "headers/RGBDiode.h"
#include "headers/Definitions.h"

RGBDiode::~RGBDiode()
{
  memset(this, NULL, sizeof(*this));
}

RGBDiode::RGBDiode()
{
  this->channels = new byte[RGBD_CHANNELS]{0x00};
  this->pinsInfo = new byte[RGBD_CHANNELS]{
      RED_PWMC,
      GRN_PWMC,
      BLU_PWMC};
  this->InitializeBus();
}

RGBDiode::RGBDiode(byte *clr)
{
  this->pinsInfo = new byte[RGBD_CHANNELS]{
      RED_PWMC,
      GRN_PWMC,
      BLU_PWMC};
  this->channels = clr;
  this->InitializeBus();
}

void RGBDiode::SwitchColor(byte *clr)
{
  this->channels = clr;
  for (byte i(0); i < RGBD_CHANNELS; i++)
  {
    analogWrite(this->pinsInfo[i], ~this->channels[i]);
  }
}

inline void RGBDiode::InitializeBus()
{
    for (byte i(0); i < RGBD_CHANNELS; i++)
    {
        analogWrite(this->pinsInfo[i], ~this->channels[i]);
    }
}

//#endif