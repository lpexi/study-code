#include <iostream>

#include "sensor_tools.hpp"

int main()
{  
    Sensor sensor{50.0, 5.0};

    sensor.celciusToFahrenheit();
    sensor.calibrate();
    sensor.printReading();

    return 0;
}