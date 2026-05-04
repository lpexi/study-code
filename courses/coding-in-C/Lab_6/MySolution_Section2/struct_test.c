/**
 * Filename: struct_test.c
 * Created on: 2024-06-01
 * 
 * Create a struct named Car with three fields: fuel_level and max_fuel_level (float) and model (char array).
 * Write a function called refuel() that:
 *
 * - Takes a pointer to a Car struct.
 * - Takes an amount (float) of fuel to add.
 * - increases the car's current fuel level if it does not exceed the max_fuel_level of the car.
 * 
 * In main, initialize a car with a low fuel level, call the refuel function, and print the result.
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * Define the Car struct and the refuel function
 */
struct Car 
{
    float fuel_level;
    float max_fuel_level;
    char model[50];
};

/**
 * Refuel the car by adding the specified amount of fuel, ensuring it does not exceed max_fuel_level.
 *
 * @param car Pointer to the Car struct to be refueled.
 * @param amount Amount of fuel to add (in liters).
 */
void refuel(struct Car* car, float amount) 
{
    if (car->fuel_level + amount <= car->max_fuel_level) 
    {
        car->fuel_level += amount;
    }
}

/**
 * Main function to demonstrate the refueling of a car.
 */
int main()
{
    struct Car myCar = {10.0f, 50.0f, "Toyota Camry"};
        printf("Initial fuel level: %.2f\n", myCar.fuel_level);
        refuel(&myCar, 15.0f);
        printf("Fuel level after refueling: %.2f\n", myCar.fuel_level);
    return 0;
}