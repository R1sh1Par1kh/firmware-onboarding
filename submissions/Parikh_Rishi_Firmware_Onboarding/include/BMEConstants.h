#pragma once

#include <Arduino.h>

namespace BMEConstants
{
    // LED configuration
    constexpr uint8_t LED_PIN = LED_BUILTIN;

    // BME280 I2C address
    constexpr uint8_t I2C_ADDRESS = 0x76;

    // BME280 SPI chip select pin
    constexpr uint8_t SPI_CS_PIN = 10;

    // Temperature range in Celsius
    constexpr float MIN_TEMP = 15.0f;
    constexpr float MAX_TEMP = 35.0f;

    // LED blink intervals in milliseconds
    constexpr unsigned long MIN_BLINK_INTERVAL = 100;
    constexpr unsigned long MAX_BLINK_INTERVAL = 1000;
}