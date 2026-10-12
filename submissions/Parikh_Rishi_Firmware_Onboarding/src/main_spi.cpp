#include <Arduino.h>
#include <math.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMESPIInterface bmeSPI;

LEDController ledController;

void setup()
{
    Serial.begin(115200);

    ledController.begin();

    if (!bmeSPI.begin())
    {
        Serial.println("BME280 SPI initialization failed!");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("BME280 SPI initialized successfully!");
}

void loop()
{
    static unsigned long previousReadMillis = 0;

    static float temperature = NAN;

    unsigned long currentMillis = millis();

    if (currentMillis - previousReadMillis >= 1000)
    {
        previousReadMillis = currentMillis;

        temperature = bmeSPI.readTemperature();

        if (!isnan(temperature))
        {
            Serial.print("Temperature: ");
            Serial.print(temperature);
            Serial.println(" C");
        }
        else
        {
            Serial.println("Temperature reading failed!");
        }
    }

    ledController.update(temperature);
}