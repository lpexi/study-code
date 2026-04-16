#include <iostream>
#include <string>

class Note  
{
private:
    std::string* text;

public:
    Note(std::string)
    {
        std::cout << "Type in your message";
        std::cin >> *text;
    }
        
    ~Note()
    {
        delete text;
        std::cout << "Memory released" << std::endl;
    }
    void display()
    {
        std::cout << *text << std::endl;
    }
};


int main()
{
    Note note1("Hello, World!");
    Note note2 = note1; // This will cause a shallow copy issue

    note1.display();
    note2.display();

    return 0;
}

