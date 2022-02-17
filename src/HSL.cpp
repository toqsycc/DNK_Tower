//#ifdef COMPILE_FOR_MEGA2560

#include "headers/HSL.h"

HSL::~HSL()
{
  delete[] colorInfo;
  memset(this, NULL, sizeof(*this));
}

HSL::HSL(double h = 0.0, double s = 0.0, double l = 0.0)
{
  colorInfo = new byte[3]{0x00};

  if (s <= 0.0)
    for (byte i(0); i < 3; i++)
      colorInfo[i] = (byte)(255.0 * l);

  else
  {
    double q = (l < 0.5 ? l * (1.0 + s) : l + s - l * s);
    double p = 2.0 * l - q;
    colorInfo[0] = (byte)(255.0 * HueToRGB(p, q, h + 1.0 / 3.0));
    colorInfo[1] = (byte)(255.0 * HueToRGB(p, q, h));
    colorInfo[2] = (byte)(255.0 * HueToRGB(p, q, h - 1.0 / 3.0));
  }
}

double HSL::HueToRGB(double p, double q, double t)
{
  if (t < 0.0)
    t += 1;
  if (t > 1.0)
    t -= 1;
  if (t < (1.0 / 6.0))
    return p + (q - p) * 6.0 * t;
  if (t < (1.0 / 2.0))
    return q;
  if (t < (2.0 / 3.0))
    return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
  return p;
}

//#endif