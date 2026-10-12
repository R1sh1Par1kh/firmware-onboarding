#include "LEDController.h"

#include <math.h>

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    digitalWrite(BMEConstants::LED_PIN, LOW);

    previousMillis = millis();

    ledState = false;
}

unsigned long LEDController::calculateBlinkInterval(
    float temperature
)
{
    if (temperature < BMEConstants::MIN_TEMP)
    {
        temperature = BMEConstants::MIN_TEMP;
    }

    if (temperature > BMEConstants::MAX_TEMP)
    {
        temperature = BMEConstants::MAX_TEMP;
    }

    float ratio =
        (temperature - BMEConstants::MIN_TEMP) /
        (BMEConstants::MAX_TEMP - BMEConstants::MIN_TEMP);

    float interval =
        BMEConstants::MAX_BLINK_INTERVAL -
        ratio *
        (BMEConstants::MAX_BLINK_INTERVAL -
         BMEConstants::MIN_BLINK_INTERVAL);

    return static_cast<unsigned long>(interval);
}

void LEDController::update(float temperature)
{
    if (isnan(temperature))
    {
        digitalWrite(BMEConstants::LED_PIN, LOW);
        ledState = false;
        previousMillis = millis();
        return;
    }

    blinkInterval = calculateBlinkInterval(temperature);

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= blinkInterval)
    {
        previousMillis = currentMillis;

        ledState = !ledState;

        digitalWrite(
            BMEConstants::LED_PIN,
            ledState ? HIGH : LOW
        );
    }
}