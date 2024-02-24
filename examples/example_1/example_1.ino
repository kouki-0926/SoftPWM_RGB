/** **************************************
 * @example example_1.ino
 * @brief   SoftPWM_RGBライブラリの使用例
 * @author  https://github.com/kouki-0926
 ************************************** **/

#include <SoftPWM_RGB.hpp>

const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;

RGB rgb(redPin, greenPin, bluePin);

void setup() { rgb.init(); }

const int delayTime = 250;
void loop() {
    for (int i = 0; i < 255; i++) {
        rgb.RGB_LED(      0,       i, 255 - i, 10);
    }
    for (int i = 0; i < 255; i++) {
        rgb.RGB_LED(      i, 255 - i,       0, 10);
    }
    for (int i = 0; i < 255; i++) {
        rgb.RGB_LED(255 - i,       0,       i, 10);
    }

    int num = 3;
    while (num--) {
        rgb.ResetFadeTime();
        rgb.on(delayTime);
        rgb.off(delayTime);
    }

    num = 3;
    while (num--) {
        rgb.SetFadeTime(delayTime, delayTime);
        rgb.on(delayTime);
        rgb.off(delayTime);
    }

    rgb.Fade(1000);
}