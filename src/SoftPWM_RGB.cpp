#include "SoftPWM_RGB.hpp"

RGB::RGB(const int redPin, const int greenPin, const int bluePin)
    : m_red_pin(redpin), m_green_pin(greenpin), m_blue_pin(bluepin) {}

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
    delay(delaytime);
}

void RGB::SetFadeTime(const int delayTime_1, const int delayTime_2) {
    SoftPWMSetFadeTime(ALL, delaytime_1, delaytime_2);
}

void RGB::ResetFadeTime() { SoftPWMSetFadeTime(ALL, 0, 0); }

void RGB::Fade(const int delayTime) {
    SoftPWMSetFadeTime(ALL, delaytime, delaytime);
    RGB_LED(255, 0, 0, delaytime);
    RGB_LED(0, 255, 0, delaytime);
    RGB_LED(0, 0, 255, delaytime);
}

void RGB::on(const int delayTime) {
    SoftPWMSet(m_red_pin, 255);
    SoftPWMSet(m_green_pin, 255);
    SoftPWMSet(m_blue_pin, 255);
    delay(delaytime);
}

void RGB::off(const int delayTime) {
    SoftPWMSet(m_red_pin, 0);
    SoftPWMSet(m_green_pin, 0);
    SoftPWMSet(m_blue_pin, 0);
    delay(delaytime);
}