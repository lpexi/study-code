#include <stdlib>
#include <string>
#include <stdexcept>

class ConfigLoader
{
private:
    /* data */
public:
    void load(const std::string filename) 
    {
        if (filename == "missing.cfg")
        {
            std::cout << "Could not open file" << "/n";
        }
    }
};