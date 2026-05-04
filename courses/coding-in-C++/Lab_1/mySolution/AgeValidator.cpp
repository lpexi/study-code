#include <iostream>
#include <cstdint>

namespace validation
{
    const std::uint8_t ADULT_AGE_LIMIT = 18;
    const std::uint8_t SENIOR_AGE_LIMIT = 65;

    bool isAdult(std::uint8_t age)
    {
        return age >= ADULT_AGE_LIMIT;
    }

    bool isSenior(std::uint8_t age)
    {
        return age >= SENIOR_AGE_LIMIT;
    }
}

int main()
{
    const uint8_t MAX_AGE = 150;
    int age = 0;

    std::cout << "Please enter your age:";

    while (true)
    {
        if (!(std::cin >> age))
        {
            std::cout << "You did not enter a valid number. Please try again. \n";
            std::cin.clear();
        }

        if (age > MAX_AGE)
        {
            std::cout << "You did not enter a valid number. Please try again. \n";
        }
        
        else if (age < 0)
        {
            std::cout << "Negative values are not allowed. Please try again \n";
        }
        
        else
        {
            break;
        }

        std::cout << "Please enter your Age: ";
    }
    
    std::cout << "You are " << age << " years old. \n";

    if (validation::isSenior(age))
    {
        std::cout << "That means your a senior citizen \n";
    }
    
    else if (validation::isAdult(age))
    {
        std::cout << "That means your an adult \n";
    }

    else
    {
        std::cout << "That means that you are still a kid or teenager \n";
    }

    return 0;
    
}