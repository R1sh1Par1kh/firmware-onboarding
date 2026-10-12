#pragma once

#include <Arduino.h>

#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void begin();

    void update(float temperature);

private:
    unsigned long calculateBlinkInterval(
        float temperature
    );

    unsigned long previousMillis = 0;

    unsigned long blinkInterval = 1000;

    bool ledState = false;
};