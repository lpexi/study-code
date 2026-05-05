/**
 * @file inheritanceBasics.cpp
 * @author @lpexi
 * @brief This file contains the solution to Lab 3 section 2. A User class is created and from this
 * class, multible derived classes with inheritance are created to train basic inheritance in C++.
 * To see whats happening, the info stored in the Sturcts is printed to the terminal
 * @version 0.1
 * @date 2026-05-05
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <cstdint>
#include <string>

/*
 Only protected member can be inherited by the derived classes and at the same time not be used
 outside of the class. If one would use private, the attributes would not be visible ore accessable
 in the derived classes.
*/
class User
{
private:

protected:
    std::string name;
    std::uint_fast16_t id;

public:
    /**
     * @brief Construct a new User object
     * 
     * @param name  Name of the user
     * @param id    ID of the user 
     */
    User(std::string name, std::uint_fast16_t id);
    /**
     * @brief Prints the stored information within the class User
     * Prints the name and ID to the terminal
     */
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
    /**
     * @brief Construct a new Student object
     * 
     * @param name      Name of the student
     * @param id        Student ID
     * @param matrNr    Matrikel number of student
     */
    Student(std::string name, std::uint_fast16_t id, std::uint_fast32_t matrNr);

    /**
     * @brief Prints the info held within the Student class
     * Prints the Name, Student ID and Matrikel number
     */
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
    /**
     * @brief Construct a new Instructor object
     * 
     * @param name          Name of Instructor
     * @param id            ID of instructor
     * @param employeeNr    Emloyee number of Instructor 
     */
    Instructor(std::string name, std::uint_fast16_t id, std::uint_fast16_t employeeNr);

    /**
     * @brief Prints the info held within the Instructor class
     * Prints the Name, Instructor ID and Employee number
     */
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