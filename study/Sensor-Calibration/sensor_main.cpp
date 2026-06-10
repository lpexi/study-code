#include <iostream>

#include "sensor_tools.hpp"

int main()
{  
    Sensor sensorOutside{50.0, 5.0};
    Sensor sensorInside{20.0, 5.0};

    sensorOutside.celciusToFahrenheit();
    sensorOutside.calibrate();
    sensorOutside.printReading();

    sensorInside.celciusToFahrenheit();
    sensorInside.calibrate();
    sensorInside.printReading();

    return 0;
}