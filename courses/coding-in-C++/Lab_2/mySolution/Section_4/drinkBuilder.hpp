#ifndef DRINK_BUILDER
#define DRINK_BUILDER

constexpr std::uint_fast16_t MIN_TEMP = 0;
constexpr std::uint_fast16_t MAX_TEMP = 100;
constexpr std::uint_fast16_t STD_TEMP = 10;
constexpr std::uint_fast16_t MIN_SUGAR = 0;
constexpr std::uint_fast16_t MAX_SUGAR = 10;
constexpr std::uint_fast16_t STD_SUGAR = 0;
constexpr bool STD_MILK = false;

class DrinkBuilder
{
private:
    std::string name;
    std::uint_fast16_t sugar;
    std::uint_fast16_t temperature;
    bool withMilk;
    
public:
    /**
     * @brief Construct a new Drink Builder object
     * 
     * @param[in] name          Name of the drink
     * @param[in] sugar         The shuger amoubt of the drink
     * @param[in] temperature   Temperature of the drink
     * @param[in] withMilk      Is the drink to be made with milk
     */
    DrinkBuilder(const std::string &name, std::uint_fast16_t sugar, std::uint_fast16_t temperature, bool withMilk);

    /**
     * @brief Set name of the drink
     * 
     * @param[in] name          New name of the drink
     * @return                  Reference to object for chaining 
     */
    DrinkBuilder &setName(const std::string &name);

    /**
     * @brief Set the Suger amount
     * 
     * @param[in] sugar         Suger amount of the drink 
     * @return                  Reference to object for chaining 
     */
    DrinkBuilder &setSugar(std::uint_fast16_t sugar);

    /**
     * @brief Set the Temperature of the drink
     * 
     * @param[in] temperature   Temperature of the drink
     * @return                  Reference to object for chaining 
     */
    DrinkBuilder &setTemperature(std::uint_fast16_t temperature);

    /**
     * @brief Set if the milk is to be made with or without milk
     * 
     * @param[in] with_milk     True if milk should be added
     * @return                  Reference to current object for chaining
     */
    DrinkBuilder &setWithMilk(bool withMilk);

    /**
     * @brief Prints the drink variables in the terminal
     * 
     * @return                  Reference to current object for chaining 
     */
    const DrinkBuilder &print() const;

    /**
     * @brief Checks if the entered configuration is valid
     * 
     * @return                  Reference to current object for chaining
     */
    bool isValid() const;

};



#endif