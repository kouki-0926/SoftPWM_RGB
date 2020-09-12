#include <SoftPWM_RGB.h>

const int redpin=13;
const int greenpin=12;
const int bluepin=11;

RGB rgb(redpin,greenpin,bluepin);

void setup(){
  rgb.init();
}

void loop(){
  rgb.Fade(1000);
}
