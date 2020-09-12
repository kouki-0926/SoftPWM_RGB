#include <SoftPWM_RGB.h>

const int redpin=13;
const int greenpin=12;
const int bluepin=11;

RGB rgb(redpin,greenpin,bluepin);

void setup(){
  rgb.init();
}

int delaytime=500;
void loop(){
  rgb.RGB_LED(64,0,64,100);

  int num=3;
  while(num--){
    rgb.SetFadeTime(delaytime,delaytime);
    rgb.on(delaytime);
    rgb.off(delaytime);
  }
  
  num=3;
  while(num--){
    rgb.ResetFadeTime();
    rgb.on(delaytime);
    rgb.off(delaytime);
  }

  rgb.Fade(1000);
}
