/** **************************************
 * @file   SoftPWM_RGB.hpp
 * @brief  SoftPWM_RGBライブラリのヘッダファイル
 * @author https://github.com/kouki-0926
 ************************************** **/

#ifndef SOFTPWM_RGB_HPP_
#define SOFTPWM_RGB_HPP_

#include <SoftPWM.h>
#include <arduino.h>

class RGB {
   public:
    RGB(const int redPin, const int greenPin, const int bluePin);

    void init();
    void RGB_LED(const int redValue, const int greenValue, const int blueValue, const int delayTime);

    void SetFadeTime(const int delayTime_1, const int delayTime_2);
    void ResetFadeTime();
    void Fade(const int delayTime);

    void on(const int delayTime);
    void off(const int delayTime);

   private:
    const int m_red_pin;
    const int m_green_pin;
    const int m_blue_pin;
};

#endif  // SOFTPWM_RGB_HPP_