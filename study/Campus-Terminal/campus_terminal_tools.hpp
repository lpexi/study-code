#ifndef CAMPUS_TERMINAL_TOOLS_HPP
#define CAMPUS_TERMINAL_TOOLS_HPP

#include <string>

extern std::string name; 
extern std::string course;
extern std::string currentTopic;
extern std::string studyGoal;

bool askContinue(const std::string &question);

std::string getInput(const std::string &question);

void getData(std::string &name,
             std::string &course,
             std::string &currentTopic,
             std::string &studyGoal);

void printData(std::string &name,
               std::string &course,
               std::string &currentTopic,
               std::string &studyGoal);

#endif // CAMPUS_TERMINAL_TOOLS_HPP