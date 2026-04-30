#include <iostream>
#include <cstdint>
#include <string>

class user
{
private:

protected:
    std::string name;
    std::uint_fast16_t id;

public:
    user(std::string name, std::uint_fast16_t id);
};

user::user(std::string name, std::uint_fast16_t id) : name(name), id(id)
{
    std::cout << "Constructor of user" << std::endl;
    void printInfo();
}

void printInfo()
{
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name << '\n';
}

class student : public user
{
private:
    std::uint_fast16_t matrNr;

protected:

public:

    Student(std::string name, int id, int matNr) : User(name, id), matNr(matNr)
    {
        std::cout << "Constructor of Student" << std::endl;
    };
};