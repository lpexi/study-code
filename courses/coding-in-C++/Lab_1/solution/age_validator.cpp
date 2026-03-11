#include <iostream>
#include <cstdint>

namespace validation{

    bool isAdult(std::uint8_t age){
        return age >= 18;
    }

    bool isSenior(std::uint8_t age){
        return age >= 65;
    }
}

int main(){

    int age = 0; 
    /* Why we do not use std::uint8_t here?
    /* std::uint8_t is usually an alias for unsigned char
    /* Hence, the first number entered would be converted into an ASCII code
    /* and so the code would not work
    /*
    /* Other options would be:
    /* std::uint16_t or std::uint32_t increasing the needed storage
    /* std::uint_least8_t ensuring the minimum size of 8 Bit
    /* std::uint_fast8_t ensuring using the most efficient data type for the cpu
    */

    std::cout << "Please enter your age: ";
    std::cin >> age;

    std::cout << "You are " << age << " years old." << std::endl;

    if(validation::isSenior(static_cast<std::uint8_t>(age))){

        std::cout << "That means that you are a senior citizen." << std::endl;
    }else if(validation::isAdult(static_cast<std::uint8_t>(age))){
        std::cout << "That means that you are an adult." << std::endl;
    }else{
        std::cout << "That means that you are still a kid or teenager." << std::endl;
    }

    return 0;
}