#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin()
{
    Wire.begin();

    return bme.begin(
        BMEConstants::I2C_ADDRESS,
        &Wire
    );
}

float BMEI2CInterface::readTemperature()
{
    return bme.readTemperature();
}