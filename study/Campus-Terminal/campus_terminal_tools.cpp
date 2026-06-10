#include <iostream>
#include <string>
#include <limits>

std::string name; 
std::string course;
std::string currentTopic;
std::string studyGoal;

bool askContinue(const std::string &question)
{
    std::string decision;

    while(true)
    {
        
        std::cout << question << " (Y/N)" << std::endl;
        std::getline(std::cin, decision);

        if (decision == "Y" || decision == "y")
        {
            return true;
        }
        else if (decision == "N" || decision == "n")
        {
            return false;
        }

        std::cout << "Please enter Y or N. Please try again" << std::endl;
    }
}

std::string getInput(const std::string &question)
{
    std::string input;

    while (input.empty())
    {
        std::cout << question << std::endl;
        std::getline(std::cin, input);

        if(input.empty())
        {
            std::cout << "Please enter something. Try again :)" << std::endl;
        }
        else if(std::cin.fail())
        {
            std::cout << "Input faild. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return input;
}


void getData(std::string &name,
             std::string &course,
             std::string &currentTopic,
             std::string &studyGoal)
{
    name = getInput("Whats your name?");
    course = getInput("Whats your course?");
    currentTopic = getInput("Whats the current topic?");
    studyGoal = getInput("Whats today's study goal?");
}

void printData(std::string &name,
               std::string &course,
               std::string &currentTopic,
               std::string &studyGoal)
{
    std::cout << std::endl << "========= Campus-Terminal =========" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Course: " << course << std::endl;
    std::cout << "Current topic: " << currentTopic << std::endl;
    std::cout << "Study goal: " << studyGoal << std::endl;
}