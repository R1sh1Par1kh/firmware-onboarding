#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : bme(BMEConstants::SPI_CS_PIN)
{
}

bool BMESPIInterface::begin()
{
    SPI.begin();

    return bme.begin();
}

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}