#include "report_utils.hpp"

#include <iomanip>
#include <iostream>
#include <limits>

void readScore(const std::string &text, std::uint_fast8_t &value)
{
    const std::uint_fast8_t max_points = 100;

    while (true)
    {
        std::cout << text;

        if (!(std::cin >> value))
        {
            std::cout << "Error: Not a valid number. Please try again. \n";
            std::cin.clear();
            continue;
        }

        if (value > max_points)
        {
            std::cout << "Error: Not in the valid number range. Please try again. \n";
            continue;
        }
        break;
    }
}

void readStudentData(std::string &name,
                     std::uint_fast8_t &homework,
                     std::uint_fast8_t &midterm,
                     std::uint_fast8_t &final_exam)
{
    std::cout << "Enter the student's name: ";
    std::cin >> std::ws;

    if (!(std::getline(std::cin, name)))
    {
        std::cout << "Error while reading input. \n";
    }

    readScore("Enter homework score: ", homework);
    readScore("Enter midterm score: ", midterm);
    readScore("Enter final exam score: ", final_exam);
}

void calculateGrade(std::uint_fast8_t &homework,
                    std::uint_fast8_t &midterm,
                    std::uint_fast8_t &final_exam,
                    float &final_grade,
                    std::string &letter_grade)
{
    const int GRADE_A = 90;
    const int GRADE_B = 80;
    const int GRADE_C = 70;
    const int GRADE_D = 60;
    const int GRADE_E = 50;

    const float FACTOR_HOMEWORK = 0.4;
    const float FACTOR_MIDTERM = 0.25;
    const float FACTOR_FINAL_EXAM = 0.35;

    final_grade = homework * FACTOR_HOMEWORK + midterm * FACTOR_MIDTERM + final_exam * FACTOR_FINAL_EXAM;

    if (final_grade >= GRADE_A)
    {
        letter_grade = "A";
    }

    else if (final_grade >= GRADE_B)
    {
        letter_grade = "B";
    }
    
    else if (final_grade >= GRADE_C)
    {
        letter_grade = "C";
    }

    else if (final_grade >= GRADE_D)
    {
        letter_grade = "D";
    }
    
    else if (final_grade >= GRADE_E)
    {
        letter_grade = "E";
    }

    else
    {
        letter_grade = "F";
    }

}

