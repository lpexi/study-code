#include "../include/report_utils.hpp"

#include <iomanip>
#include <iostream>
#include <limits>

void readScore(const std::string &text, std::uint_fast16_t &value)
{
    const std::uint_fast16_t MAX_POINTS = 100;

    while (true)
    {
        std::cout << text;

        if (!(std::cin >> value))
        {
            std::cout << "Error: Not a valid number. Please try again. \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (value > MAX_POINTS)
        {
            std::cout << "Error: Not in the valid number range. Please try again. \n";
            continue;
        }
        break;
    }
}

void readStudentData(std::string &name,
                     std::uint_fast16_t &homework,
                     std::uint_fast16_t &midterm,
                     std::uint_fast16_t &final_exam)
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

void calculateGrade(std::uint_fast16_t &homework,
                    std::uint_fast16_t &midterm,
                    std::uint_fast16_t &final_exam,
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

void printReport(const std::string &name,
                 std::uint_fast16_t &homework,
                 std::uint_fast16_t &midterm,
                 std::uint_fast16_t &final_exam,
                 float final_grade,
                 const std::string &letter_grade)
{
    std::string status = "";

    if (letter_grade == "A" || letter_grade == "B" || letter_grade == "C")
    {
        status = "PASS";
    }

    else if (letter_grade == "D" || letter_grade == "E")
    {
        status = "CONDITIONAL PASS";
    }
    
    else if (letter_grade == "F")
    {
        status = "FAIL";
    }

    std::cout << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::left << std::setfill(' ') << "Student Report" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::left << std::setfill(' ') << "Name: " << name << std::endl
              << std::endl;
    std::cout << "Scores" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Homework" << std::right << ": " << std::fixed << std::setprecision(2) << static_cast<double>(homework) << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Midterm" << std::right << ": " << std::fixed << std::setprecision(2) << static_cast<double>(midterm) << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Final Exam" << std::right << ": " << std::fixed << std::setprecision(2) << static_cast<double>(final_exam) << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Final Grade" << std::right << ": " << std::fixed << std::setprecision(2) << final_grade << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Letter Grade" << std::right << ": " << letter_grade << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Status" << std::right << ": " << status << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
}

