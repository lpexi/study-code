#include <iostream>
#include <cstdint>
#include <string>

class User
{
private:

protected:
    std::string name;
    std::uint_fast16_t id;

public:
    User(std::string name, std::uint_fast16_t id);
    
    void printInfo();
};

User::User(std::string name, std::uint_fast16_t id) : name(name), id(id)
{
    std::cout << "Constructor of User" << std::endl;
    void printInfo();
}

void User::printInfo()
{
    std::cout << "User info ID: " << this->id << '\n';
    std::cout << "User info Name: " << this->name << '\n';
}

class Student : public User
{
private:
    std::uint_fast32_t matrNr;

public:

    Student(std::string name, std::uint_fast16_t id, std::uint_fast32_t matrNr);

    void printRole();
};

Student::Student(std::string name, std::uint_fast16_t id, std::uint_fast32_t matrNr)
                    : User(name, id), matrNr(matrNr)
{
    std::cout << "Constructor of Student" << std::endl;
}

void Student::printRole()
{
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name << '\n';
    std::cout << "Matrikel number: " << this->matrNr << '\n';
}

class Instructor : public User
{
private:
    std::uint_fast16_t employeeNr;

public:
    Instructor(std::string name, std::uint_fast16_t id, std::uint_fast16_t employeeNr);

    void printRole();
};

Instructor::Instructor(std::string name, std::uint_fast16_t id, std::uint_fast16_t employeeNr)
                        : User(name, id), employeeNr(employeeNr)
{
    std::cout << "Constructor of Instructor" << '\n';
}

void Instructor::printRole()
{
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name << '\n';
    std::cout << "Employee number: " << this->employeeNr << '\n';
}

int main()
{
    
    Student student1("Kai Rosenkranz", 1, 123456);
    Instructor instructor1("Nobuo Uematsu", 99, 10000);

    student1.printInfo();
    student1.printRole();

    instructor1.printInfo();
    instructor1.printRole();

    return 0;
}