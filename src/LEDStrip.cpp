//#ifdef COMPILE_FOR_MEGA2560

#include "headers/LEDStrip.h"
#include "headers/HSL.h"
#include "headers/Definitions.h"

LEDstrip::LEDstrip()
{
  isReverseBase = false;
  isReverseSide = false;
  isReverseTop = false;
  currentBase = 0;
  currentSide = 0;
  currentTop = 0;
}

void LEDstrip::activate()
{
  FastLED.addLeds<WS2812, PIN_NUM_BASE, GRB>(leds, 8);
  FastLED.addLeds<WS2812, PIN_NUM_SIDE_1, GRB>(leds_side1, 4);
  FastLED.addLeds<WS2812, PIN_NUM_SIDE_2, GRB>(leds_top, 3);
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

void LEDstrip::pushLED(){
  if(!isReverseBase && currentBase <= 7)
  {
    HSL color(0.0, 1.0, 0.25);
    byte* c = color.getColorInfoRGB();
    leds[currentBase] = CRGB(c[0], c[1], c[2]);
    FastLED[0].showLeds();
    currentBase++;
    isReverseBase = currentBase == 8 ? true : false;

    Serial.println(currentBase);
  }
  if(isReverseBase && currentBase >= 0)
  {    
    HSL color(0.5, 1.0, 0.25);
    byte* c = color.getColorInfoRGB();
    leds[currentBase] = CRGB(c[0], c[1], c[2]);
    FastLED[0].showLeds();
    currentBase--;
    isReverseBase = currentBase <= 0 ? false : true;
    Serial.println(currentBase);
  }
}

void LEDstrip::pushSideLED(){
  if(!isReverseSide && currentSide <= 3)
  {
    HSL color(0.0, 1.0, 0.25);
    byte* c = color.getColorInfoRGB();
    leds_side1[currentSide] = CRGB(c[0], c[1], c[2]);
    FastLED[1].showLeds();    
    currentSide++;
    isReverseSide = currentSide == 4 ? true : false;
  }
  if(isReverseSide && currentSide >= 0)
  {    
    HSL color(0.5, 1.0, 0.25);
    byte* c = color.getColorInfoRGB();
    leds_side1[currentSide] = CRGB(c[0], c[1], c[2]);
    FastLED[1].showLeds();
    currentSide--;
    isReverseSide = currentSide <= 0 ? false : true;
  }
}

void LEDstrip::pushTopLED(){
  if(!isReverseTop && currentTop <= 2)
  {
    HSL color(0.0, 1.0, 0.25);
    byte* c = color.getColorInfoRGB();
    leds_top[currentTop] = CRGB(c[0], c[1], c[2]);
    FastLED[2].showLeds();    
    currentTop++;
    isReverseTop = currentTop == 3 ? true : false;
  }
  if(isReverseTop && currentTop >= 0)
  {    
    HSL color(0.5, 1.0, 0.25);
    byte* c = color.getColorInfoRGB();
    leds_top[currentTop] = CRGB(c[0], c[1], c[2]);
    FastLED[2].showLeds();
    currentTop--;
    isReverseTop = currentTop <= 0 ? false : true;
  }
}
//#endif