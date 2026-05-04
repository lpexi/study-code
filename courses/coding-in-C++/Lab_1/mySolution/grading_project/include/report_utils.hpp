#ifndef REPORT_UTILS_HPP
#define REPORT_UTILS_HPP

#include <cstdint>
#include <string>

/**
 * @brief Reads the input
 * 
 * @param[in]   name            Name of the student
 * @param[in]   homework        Homework grade
 * @param[in]   midterm         Midterm result
 * @param[in]   finam_exam      Final exam result
 */
void readStudentData(std::string &name,
                     std::uint_fast16_t &homework,
                     std::uint_fast16_t &midterm,
                     std::uint_fast16_t &final_exam);

/**
 * @brief Calculates the results
 * 
 * @param[in]   homework        Homework grade
 * @param[in]   midterm         Midterm result
 * @param[in]   finam_exam      Final exam result
 * @param[out]  final_grade     The final grade as a number value
 * @param[out]  letter_grade    The final grade a s letter 
 */
void calculateGrade(std::uint_fast16_t &homework,
                    std::uint_fast16_t &midterm,
                    std::uint_fast16_t &final_exam,
                    float &final_grade,
                    std::string &letter_grade);

/**
 * @brief This function prints the report of the students evaluation
 * 
 * @param[in]   name            Name of the student
 * @param[in]   homework        Homework grade
 * @param[in]   midterm         Midterm result
 * @param[in]   finam_exam      Final exam result
 * @param[out]  final_grade     The final grade as a number value
 * @param[out]  letter_grade    The final grade a s letter 
 */
void printReport(const std::string &name,
                 std::uint_fast16_t &homework,
                 std::uint_fast16_t &midterm,
                 std::uint_fast16_t &final_exam,
                 float final_grade,
                 const std::string &letter_grade);

#endif
