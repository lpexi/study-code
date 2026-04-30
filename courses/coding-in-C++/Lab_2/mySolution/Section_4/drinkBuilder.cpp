#include <iostream>
#include <string>
#include "drinkBuilder.hpp"


DrinkBuilder::DrinkBuilder(const std::string &name, std::uint_fast16_t sugar, std::uint_fast16_t temperature, bool withMilk)
    : name(name), sugar(sugar), temperature(temperature), withMilk(withMilk)
{
    if(temperature < MIN_TEMP || temperature > MAX_TEMP)
    {
        this->temperature = STD_TEMP;
    }

    if (sugar < MIN_SUGAR || sugar > MAX_SUGAR)  
    {
        this->sugar = STD_SUGAR;
    }
    
}

DrinkBuilder &DrinkBuilder::setName(const std::string &name)
{
    this->name = name;
    return *this;
}

DrinkBuilder &DrinkBuilder::setSugar(std::uint_fast16_t sugar)
{
    this->sugar = sugar;
    return *this;
}

DrinkBuilder &DrinkBuilder::setTemperature(std::uint_fast16_t temperature)
{
    this->temperature = temperature;
    return *this;
}

DrinkBuilder &DrinkBuilder::setWithMilk(bool withMilk)
{
    this->withMilk = withMilk;
    return *this; 
}

const DrinkBuilder &DrinkBuilder::print() const
{
    using std::cout;
    using std::endl;

    cout << "Name: " << this->name << endl;
    cout << "Sugar: " << this->sugar << endl;
    cout << "Temperature: " << this->temperature << endl;
    cout << "With Milk: " << std::boolalpha << this->withMilk << endl;

    return *this;
}

bool DrinkBuilder::isValid() const
{
    bool valid = true;

    if(this->temperature < MIN_TEMP)
    {
        std::cout << "The temperature may not be below " << MIN_TEMP << "degrees." << std::endl;
        valid = false;
    }

    if(this->temperature > MAX_TEMP)
    {
        std::cout << "The temperature may not be above " << MAX_TEMP << "degrees." << std::endl;
        valid = false;
    }

    if(this->sugar < MIN_SUGAR)
    {
        std::cout << "The sugar may not be below " << MIN_SUGAR << std::endl;
        valid = false;
    }

    if(this->temperature > MAX_TEMP)
    {
        std::cout << "The sugar may not be above " << MAX_SUGAR << std::endl;
        valid = false;
    }

    if (valid)
    {
        std::cout << "That's perfect!" << std::endl;
    }

    return valid;
}


int main()
{
    DrinkBuilder drink1("Gin Tonic", 0, 15, false);
    drink1.print();

    std::cout << std::endl;

    drink1.setName("White Russian")
        .setSugar(5)
        .setTemperature(4)
        .setWithMilk(true)
        .print();

    drink1.isValid();
}
