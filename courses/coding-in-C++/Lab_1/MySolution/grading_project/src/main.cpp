#include <cstdint>
#include <string>

#include "report_utils.hpp"

int main()
{
    std::string name;
    std::uint_fast16_t homework = 0;
    std::uint_fast16_t midterm = 0;
    std::uint_fast16_t final_exam = 0;
    float final_grade = 0.0;
    std::string letter_grade;

    readStudentData(name, 
                    homework, 
                    midterm, 
                    final_exam);

    calculateGrade(homework,
                   midterm, 
                   final_exam, 
                   final_grade, 
                   letter_grade);
    printReport(name, 
                homework, 
                midterm, 
                final_exam, 
                final_grade, 
                letter_grade);

    return 0;
}
