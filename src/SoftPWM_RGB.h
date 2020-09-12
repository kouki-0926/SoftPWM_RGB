#ifndef SOFTPWM_RGB_H
#define SOFTPWM_RGB_H

class RGB{
  public:
     RGB(int redpin,int greenpin,int bluepin);
     void init();
     void RGB_LED(int redValue,int greenValue,int blueValue,int delaytime);
     void SetFadeTime(int delaytime_1,int delaytime_2);
     void ResetFadeTime();
     void Fade(int delaytime);
     void on(int delaytime);
     void off(int delaytime);
  private:
     const int m_red_pin;
     const int m_green_pin;
     const int m_blue_pin;
};

#endif
