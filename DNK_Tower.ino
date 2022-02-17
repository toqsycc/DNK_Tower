#include "src/headers/Definitions.h"
#include "src/headers/CodeSanitizer.h"
#include "src/headers/DNKCore.h"
#include "src/headers/LEDStrip.h"
#include "src/headers/RGBDiode.h"
#include "src/headers/HSL.h"
#include "src/headers/Tower.h"

int main()
{
  init();
  #ifdef COMPILE_FOR_MEGA2560
    Tower *tower = new Tower();
  #endif
  #ifdef COMPILE_FOR_NANO328P
  #include "src/headers/CoProcessor.h"
    CoProcessor *proc = new CoProcessor();
  #endif
  return 0;
}
