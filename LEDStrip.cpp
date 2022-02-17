//#ifdef COMPILE_FOR_MEGA2560

#include "headers/LEDStrip.h"
#include "headers/HSL.h"
#include "headers/Definitions.h"

LEDstrip::LEDstrip()
{
}

void LEDstrip::activate()
{
  FastLED.addLeds<WS2812, PIN_NUM_BASE, GRB>(leds, 8);
  FastLED.addLeds<WS2812, PIN_NUM_SIDE_1, GRB>(leds_side1, 4);
}

void LEDstrip::showSide(double hueStart, double hueEnd, int dVal = 100)
{
  for (int i = 0; i <= 3; i++)
  {
    HSL color(hueStart, 0.5, 0.5);
    byte* c = color.getColorInfoRGB();
    leds_side1[i] = CRGB(c[0], c[1], c[2]);
    FastLED[1].showLeds();
    delay(dVal);
  }
  for (int i = 3; i >= 0; i--)
  {
    HSL color(hueEnd, 0.5, 0.5);
    byte* c = color.getColorInfoRGB();
    leds_side1[i] = CRGB(c[0], c[1], c[2]);
    FastLED[1].showLeds();
    delay(dVal);
  }
}

void LEDstrip::showRed(double hue, int dVal = 100)
{
  for (int i = 0; i <= 7; i++)
  {
    HSL color(hue, 1.0, 0.5);
    byte* c = color.getColorInfoRGB();
    leds[i] = CRGB(c[0], c[1], c[2]);
    FastLED[0].showLeds();
    delay(dVal);
  }
}

void LEDstrip::showBlue(double hue, int dVal = 100)
{
  for (int i = 7; i >= 0; i--)
  {
    HSL color(hue, 1.0, 0.5);
    byte* c = color.getColorInfoRGB();
    leds[i] = CRGB(c[0], c[1], c[2]);
    FastLED[0].showLeds();
    delay(dVal);
  }
}

void LEDstrip::turnOff(int dVal = 100)
{
  for (int i = 0; i <= 3; i++)
  {
    leds_side1[i] = CRGB::Black;
    FastLED[1].showLeds();
    delay(dVal);
  }
  for (int i = 0; i <= 7; i++)
  {
    leds[i] = CRGB::Black;
    FastLED[0].showLeds();
    delay(dVal);
  }
}

//#endif