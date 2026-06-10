#include <iostream>

#include "sensor_tools.hpp"

constexpr std::double_t convFactor{9.0 / 5.0};
constexpr std::double_t convOffset{32};

Sensor::Sensor(std::double_t raw, std::double_t calibrationOffset)
                : rawTemperature{raw},
                  temperature{raw},
                  offset{calibrationOffset}
{
}

void Sensor::celciusToFahrenheit()
{
    rawTemperature = rawTemperature * convFactor + convOffset;
}

void Sensor::FahrenheitToCelcius()
{
    rawTemperature = (rawTemperature - convOffset) / convFactor;
}

void Sensor::calibrate()
{
    temperature = rawTemperature + offset;
}

void Sensor::printReading()
{
    std::cout << "The current temperature is: " << temperature << std::endl;
    std::cout << "The current offset is:  " << offset << std::endl;
    std::cout << "The uncorrected reading is: " << rawTemperature << std::endl;
}