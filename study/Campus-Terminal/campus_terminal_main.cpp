#include <cstdlib>

#include "campus_terminal_tools.hpp"

int main()
{
    bool continueLoop = true;

    while (continueLoop)
    {
        getData(name,
                course,
                currentTopic,
                studyGoal);
    
        printData(name,
                  course,
                  currentTopic,
                  studyGoal);

        continueLoop = askContinue("Would you like to enter another table?");
        system("cls");
    }
    return 0;
}