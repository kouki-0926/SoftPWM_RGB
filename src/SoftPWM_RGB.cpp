#include <arduino.h>
#include <SoftPWM.h>
#include "SoftPWM_RGB.h"

RGB::RGB(int redpin,int greenpin,int bluepin)
:m_red_pin(redpin),m_green_pin(greenpin),m_blue_pin(bluepin){
}

void RGB::init(){
  SoftPWMBegin();
  SoftPWMSet(m_red_pin,0);
  SoftPWMSet(m_green_pin,0);
  SoftPWMSet(m_blue_pin,0);
}

void RGB::RGB_LED(int redValue,int greenValue,int blueValue,int delaytime){
  SoftPWMSet(m_red_pin,redValue);
  SoftPWMSet(m_green_pin,greenValue);
  SoftPWMSet(m_blue_pin,blueValue);
  delay(delaytime);
}

void RGB::SetFadeTime(int delaytime_1,int delaytime_2){
  SoftPWMSetFadeTime(ALL,delaytime_1,delaytime_2);
}

void RGB::Fade(int delaytime){
  SoftPWMSetFadeTime(ALL,delaytime,delaytime);
  RGB_LED(255,0,0,delaytime);
  RGB_LED(0,255,0,delaytime);
  RGB_LED(0,0,255,delaytime);
}

void RGB::on(int delaytime){
  SoftPWMSet(m_red_pin,255);
  SoftPWMSet(m_green_pin,255);
  SoftPWMSet(m_blue_pin,255);
  delay(delaytime);
}

void RGB::off(int delaytime){
  SoftPWMSet(m_red_pin,0);
  SoftPWMSet(m_green_pin,0);
  SoftPWMSet(m_blue_pin,0);
  delay(delaytime);
}
