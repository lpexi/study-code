#ifndef SENSOR_TOOLS_HPP
#define SENSOR_TOOLS_HPP

#include <iostream>

class Sensor
{
private:
    std::double_t rawTemperature = 0.0;
    std::double_t temperature = 0.0;
    std::double_t offset = 0.0;

public:
    Sensor(std::double_t rawTemperature, std::double_t offset);

    void celciusToFahrenheit();
    void FahrenheitToCelcius();
    void calibrate();
    void printReading();
};

#endif //SENSOR_TOOLS_HPP