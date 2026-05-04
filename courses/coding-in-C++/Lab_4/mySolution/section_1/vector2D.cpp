/**
 * @file vector2d.cpp
 * @brief Implementation of a 2D vector class with operator overloading.
 */
#include <iostream>
#include <cmath>

class vector2d
{
private:
    std::double_t x;
    std::double_t y;

    
public:
    /**
     * @brief Default constructor of a new vector2d object
     * Initialize the coordinates to 0.0
     */
    vector2d() : x(0.0), y(0.0) {}

    /**
     * @brief Parameterized constructor of a new vector2d object
     * 
     * @param[in] x     X coordinate 
     * @param[in] y     Y coordinate
     */
    vector2d(std::double_t x, std::double_t y) : x(x), y(y){}

    /**
     * @brief Getter method for x coordinate
     * 
     * @return std::double_t 
     */
    std::double_t getX() const
    {
        return x;
    }

    /**
     * @brief Getter method for y coordinate
     * 
     * @return std::double_t 
     */
    std::double_t getY() const
    {
        return y;
    }

    /**
     * @brief Prints the vector to standard output.
     */
    void print() const
    {
        std::cout   << "X-Coordinate: " << this->getX() << "\n"
                    << "Y-Coordinate: " << this->getY() << "\n";
    }

    /**
     * @brief Get the Magnitude of the vector
     * 
     * @return std::double_t 
     */
    std::double_t getMagnitude() const
    {
        return sqrt((x * x)+(y * y));
    }

    /**
     * @brief Get the Magnitude object rounded to a given precision
     * 
     * @param[in] precision     Number of decimal places
     * @return std::double_t 
     */
    std::double_t getMagnitude(std::int_fast16_t precision) const {}
};

std::double_t vector2d::getMagnitude(std::int_fast16_t precision) const
{
    double factor = std::pow(10.0, precision);
    double length = this->getMagnitude();

    return std::round(length * factor) / factor;
}

int main()
{
    // Part 2
    vector2d vec1(4, 5);
    vector2d vec2(1, 9);

    std::cout << vec1.getMagnitude() << std::endl;
    std::cout << vec1.getMagnitude(3) << std::endl;

}