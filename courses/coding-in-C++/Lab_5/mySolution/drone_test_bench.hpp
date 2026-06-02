#ifndef DRONE_TEST_BENCH_HPP
#define DRONE_TEST_BENCH_HPP

#include <algorithm> // std::count, std::max_element
#include <cstddef>   // std::size_t
#include <iostream>
#include <numeric> // std::accumulate
#include <string>
#include <vector>

// ---------------------------------------------------------------------------
// Task 1: Generic swap function
// ---------------------------------------------------------------------------
template <typename T>
void swapValues(T &firstValue, T &secondValue)
{
    // Ein Template ist hier besser als drei einzelne Funktionen fuer int,
    // double und std::string, weil die Tausch-Logik fuer alle Typen gleich ist.
    // Wir schreiben den Code einmal und der Compiler erzeugt die passende
    // Version fuer jeden verwendeten Typ.
    std::cout << "Before swap:\n";
    std::cout << "  First value:  " << firstValue << '\n';
    std::cout << "  Second value: " << secondValue << '\n';

    // T ist ein Platzhalter fuer den konkreten Datentyp.
    // Dadurch hat temporary immer denselben Typ wie die beiden Werte.
    T temporary = firstValue;
    firstValue = secondValue;
    secondValue = temporary;

    std::cout << "After swap:\n";
    std::cout << "  First value:  " << firstValue << '\n';
    std::cout << "  Second value: " << secondValue << '\n';
}

// ---------------------------------------------------------------------------
// Tasks 2 and 5: Generic fixed-size array printer
// ---------------------------------------------------------------------------
template <typename T, std::size_t N>
void printFrame(const T (&frame)[N])
{
    // T ist der Elementtyp, zum Beispiel int, double oder char.
    // N ist die Array-Groesse und wird automatisch vom Compiler erkannt.
    std::cout << "[";
    for (std::size_t i = 0; i < N; ++i)
    {
        std::cout << frame[i];

        // Das Komma wird nur zwischen zwei Elementen gedruckt.
        if (i + 1 < N)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

// ---------------------------------------------------------------------------
// Tasks 3 and 5: Generic fixed-size array minimum finder
// ---------------------------------------------------------------------------
template <typename T, std::size_t N>
T findMinimum(const T (&frame)[N])
{
    // Die Aufgabe sagt, dass die Groesse immer groesser als 0 ist.
    // Deshalb duerfen wir das erste Element als Startwert nehmen.
    T minimumValue = frame[0];

    // Kein STL-Algorithmus: Wir laufen manuell durch das Array.
    for (std::size_t i = 1; i < N; ++i)
    {
        if (frame[i] < minimumValue)
        {
            minimumValue = frame[i];
        }
    }

    return minimumValue;
}

// Task 5 questions:
// Why is the size no longer needed as a parameter?
// The parameter type T (&frame)[N] receives the array by reference. Because N is
// part of that type, the compiler already knows the array size at compile time.
//
// What advantage does this have compared to the previous version?
// The caller cannot accidentally pass a wrong size anymore. The function call is
// shorter, safer and still works directly with normal C-style arrays.

// ---------------------------------------------------------------------------
// Task 4: Generic function with two independent type parameters
// ---------------------------------------------------------------------------
template <typename FirstType, typename SecondType>
void composeTags(const std::string &label1,
                 const FirstType &value1,
                 const std::string &label2,
                 const SecondType &value2)
{
    // FirstType and SecondType may be different, for example std::string and int.
    std::cout << label1 << ": " << value1
              << " | " << label2 << ": " << value2 << '\n';
}

// ---------------------------------------------------------------------------
// Helper function for printing std::vector data
// ---------------------------------------------------------------------------
template <typename T>
void printVector(const std::vector<T> &data)
{
    std::cout << "[";

    // This is a range-based for loop. It visits every element in the vector.
    bool isFirstElement = true;
    for (const auto element : data)
    {
        if (!isFirstElement)
        {
            std::cout << ", ";
        }

        std::cout << element;
        isFirstElement = false;
    }

    std::cout << "]\n";
}

// ---------------------------------------------------------------------------
// Task 9 Part A: Generic numeric analysis functions for std::vector
// ---------------------------------------------------------------------------
template <typename T>
T computeSum(const std::vector<T> &data)
{
    // T{} is the neutral start value: 0 for int, 0.0 for double, etc.
    return std::accumulate(data.begin(), data.end(), T{});
}

template <typename T>
T computeMax(const std::vector<T> &data)
{
    // The lab data is non-empty. For an empty vector we return T{} to avoid
    // dereferencing data.end().
    if (data.empty())
    {
        return T{};
    }

    return *std::max_element(data.begin(), data.end());
}

// Task 9 Part C:
// This is the required template specialization for std::vector<bool>.
// For bool data, a numeric maximum is not useful. Instead, this specialized
// version returns true only if more than half of the values are true.
template <>
inline bool computeMax<bool>(const std::vector<bool> &data)
{
    if (data.empty())
    {
        return false;
    }

    const std::size_t trueCount =
        static_cast<std::size_t>(std::count(data.begin(), data.end(), true));

    return trueCount > data.size() / 2;
}

template <typename T>
double computeAverage(const std::vector<T> &data)
{
    if (data.empty())
    {
        return 0.0;
    }

    const T sum = computeSum(data);
    return static_cast<double>(sum) / static_cast<double>(data.size());
}

template <typename T>
void printMetricsReport(const std::vector<T> &data)
{
    // This report is intended for numeric data such as int and double.
    std::cout << "Raw data: ";
    printVector(data);

    std::cout << "Sum:     " << computeSum(data) << '\n';
    std::cout << "Maximum: " << computeMax(data) << '\n';
    std::cout << "Average: " << computeAverage(data) << '\n';
}

// ---------------------------------------------------------------------------
// Task 9 Part B: Import a fixed-size frame into a std::vector
// ---------------------------------------------------------------------------
template <typename T, std::size_t N>
std::vector<T> convertToVector(const T (&frame)[N])
{
    std::vector<T> result;

    // reserve does not add elements. It only prepares enough memory for N items.
    result.reserve(N);

    // The array size is known through N, so no size parameter is needed.
    for (std::size_t i = 0; i < N; ++i)
    {
        result.push_back(frame[i]);
    }

    return result;
}

#endif
