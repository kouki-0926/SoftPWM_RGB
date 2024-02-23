/** **************************************
 * @file   SoftPWM_RGB.cpp
 * @brief  SoftPWM_RGBライブラリの実装ファイル
 * @author https://github.com/kouki-0926
 ************************************** **/

#include "SoftPWM_RGB.hpp"

RGB::RGB(const int redPin, const int greenPin, const int bluePin)
    : m_red_pin(redPin), m_green_pin(greenPin), m_blue_pin(bluePin) {}

void RGB::init() {
    SoftPWMBegin();
    SoftPWMSet(m_red_pin, 0);
    SoftPWMSet(m_green_pin, 0);
    SoftPWMSet(m_blue_pin, 0);
}

void RGB::RGB_LED(const int redValue, const int greenValue, const int blueValue, const int delayTime) {
    SoftPWMSet(m_red_pin, redValue);
    SoftPWMSet(m_green_pin, greenValue);
    SoftPWMSet(m_blue_pin, blueValue);
    delay(delayTime);
}

void RGB::SetFadeTime(const int delayTime_1, const int delayTime_2) {
    SoftPWMSetFadeTime(ALL, delayTime_1, delayTime_2);
}

void RGB::ResetFadeTime() { SoftPWMSetFadeTime(ALL, 0, 0); }

void RGB::Fade(const int delayTime) {
    SoftPWMSetFadeTime(ALL, delayTime, delayTime);
    RGB_LED(255, 0, 0, delayTime);
    RGB_LED(0, 255, 0, delayTime);
    RGB_LED(0, 0, 255, delayTime);
}

void RGB::on(const int delayTime) {
    SoftPWMSet(m_red_pin, 255);
    SoftPWMSet(m_green_pin, 255);
    SoftPWMSet(m_blue_pin, 255);
    delay(delayTime);
}

void RGB::off(const int delayTime) {
    SoftPWMSet(m_red_pin, 0);
    SoftPWMSet(m_green_pin, 0);
    SoftPWMSet(m_blue_pin, 0);
    delay(delayTime);
}