#include <Arduino.h>
#include <math.h>

#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMEI2CInterface bmeI2C;

LEDController ledController;

void setup()
{
    Serial.begin(115200);

    ledController.begin();

    if (!bmeI2C.begin())
    {
        Serial.println("BME280 I2C initialization failed!");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("BME280 I2C initialized successfully!");
}

void loop()
{
    static unsigned long previousReadMillis = 0;

    static float temperature = NAN;

    unsigned long currentMillis = millis();

    if (currentMillis - previousReadMillis >= 1000)
    {
        previousReadMillis = currentMillis;

        temperature = bmeI2C.readTemperature();

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