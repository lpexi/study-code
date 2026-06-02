#include <algorithm> // std::count, std::find, std::replace, std::reverse, std::sort
#include <iostream>
#include <string>
#include <vector>

#include "drone_test_bench.hpp"

int main()
{
    std::cout << std::boolalpha;

    // =======================================================================
    // Section I: First steps with generic functions
    // =======================================================================
    std::cout << "\n========== Section I: Generic Functions ==========\n";

    // -----------------------------------------------------------------------
    // Task 1: Emergency Payload Switch
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 1: Emergency Payload Switch ---\n";

    int calibrationA = 10;
    int calibrationB = 20;
    swapValues(calibrationA, calibrationB);

    double voltageLimitA = 11.8;
    double voltageLimitB = 12.4;
    swapValues(voltageLimitA, voltageLimitB);

    std::string payloadModeA = "camera";
    std::string payloadModeB = "thermal";
    swapValues(payloadModeA, payloadModeB);

    // -----------------------------------------------------------------------
    // Tasks 2, 3 and 5: Sensor frames, minimum values and fixed sizes
    // -----------------------------------------------------------------------
    std::cout << "\n--- Tasks 2, 3 and 5: Fixed-Size Sensor Frames ---\n";

    // These are normal C-style arrays. Their sizes are part of their types:
    // int[4], double[6] and char[5].
    int integerFrame[4] = {12, 15, 18, 21};
    double doubleFrame[6] = {3.4, 2.8, 4.1, 3.9, 2.5, 3.2};
    char charFrame[5] = {'A', 'B', 'C', 'D', 'E'};

    std::cout << "Integer frame: ";
    printFrame(integerFrame);

    std::cout << "Double frame:  ";
    printFrame(doubleFrame);

    std::cout << "Char frame:    ";
    printFrame(charFrame);

    // findMinimum also receives the array by reference, so it automatically
    // knows how many elements it must inspect.
    std::cout << "Weakest integer signal: " << findMinimum(integerFrame) << '\n';
    std::cout << "Weakest double signal:  " << findMinimum(doubleFrame) << '\n';

    // -----------------------------------------------------------------------
    // Task 4: Telemetry Tag Composer
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 4: Telemetry Tag Composer ---\n";

    composeTags("Channel", std::string("motor_temp"), "Priority", 2);
    composeTags("Sensor", std::string("voltage"), "Limit", 12.4);

    // =======================================================================
    // Section II: Flight recorder data analysis
    // =======================================================================
    std::cout << "\n========== Section II: STL Containers and Algorithms ==========\n";

    // -----------------------------------------------------------------------
    // Task 6: Sort and Inspect Recorded Samples
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 6: Sort and Inspect Recorded Samples ---\n";

    std::vector<int> recordedData = {42, 17, 42, 5, 99, 17, 63, 12};

    std::cout << "Original data: ";
    printVector(recordedData);

    // std::sort rearranges the values directly inside the vector.
    std::sort(recordedData.begin(), recordedData.end());

    std::cout << "Sorted data:   ";
    printVector(recordedData);

    // std::find returns an iterator to the found element or end() if missing.
    const auto foundValue =
        std::find(recordedData.begin(), recordedData.end(), 63);

    if (foundValue == recordedData.end())
    {
        std::cout << "Value 63 exists: false\n";
    }
    else
    {
        std::cout << "Value 63 exists: true\n";
    }

    // -----------------------------------------------------------------------
    // Task 7: Noise Cleanup Pipeline
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 7: Noise Cleanup Pipeline ---\n";

    std::vector<int> cleanupData = {7, -1, 13, -1, 21, 21, 8, -1, 8};

    std::cout << "Raw data:                 ";
    printVector(cleanupData);

    // std::replace changes every -1 to 0.
    std::replace(cleanupData.begin(), cleanupData.end(), -1, 0);

    std::cout << "After replacing -1 by 0:  ";
    printVector(cleanupData);

    // std::count counts how often the value 8 appears.
    const int valueToCount = 8;
    const int countOfEight =
        static_cast<int>(std::count(cleanupData.begin(), cleanupData.end(), valueToCount));
    std::cout << "Occurrences of value 8:   " << countOfEight << '\n';

    // std::reverse turns the order around in place.
    std::reverse(cleanupData.begin(), cleanupData.end());

    std::cout << "After reversing:          ";
    printVector(cleanupData);

    // -----------------------------------------------------------------------
    // Task 8: Manual Iterator Walk
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 8: Manual Iterator Walk ---\n";

    std::cout << "Iterator output: ";

    // We use an explicit iterator type here instead of a range-based for loop.
    for (std::vector<int>::iterator it = cleanupData.begin();
         it != cleanupData.end();
         ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    // What does *it do?
    // *it dereferences the iterator. That means it gives access to the value
    // stored at the current iterator position.
    //
    // What does ++it do?
    // ++it moves the iterator forward to the next element in the vector.

    // =======================================================================
    // Section III: Drone Black Box Analyzer
    // =======================================================================
    std::cout << "\n========== Section III: Drone Black Box Analyzer ==========\n";

    // -----------------------------------------------------------------------
    // Task 9 Part A: Reusable analysis functions
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 9A: Numeric Dataset Reports ---\n";

    std::vector<int> temperatureSamples = {24, 25, 23, 27, 26};
    std::vector<double> voltageSamples = {11.9, 12.1, 12.0, 11.8, 12.2};

    std::cout << "Temperature samples:\n";
    printMetricsReport(temperatureSamples);

    std::cout << "\nVoltage samples:\n";
    printMetricsReport(voltageSamples);

    // -----------------------------------------------------------------------
    // Task 9 Part B: Frame import from fixed-size sensor data
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 9B: Fixed-Size Frame Import ---\n";

    double vibrationFrame[5] = {0.12, 0.18, 0.09, 0.21, 0.15};

    // convertToVector accepts the array directly. No separate size is passed.
    std::vector<double> vibrationSamples = convertToVector(vibrationFrame);

    std::cout << "Vibration frame as vector:\n";
    printMetricsReport(vibrationSamples);

    // -----------------------------------------------------------------------
    // Task 9 Part C: Status stream specialization
    // -----------------------------------------------------------------------
    std::cout << "\n--- Task 9C: Boolean Status Stream ---\n";

    std::vector<bool> motorStatus = {true, true, false, true, false, true};

    std::cout << "Motor status stream: ";
    printVector(motorStatus);

    // For std::vector<bool>, computeMax uses the specialization from the header.
    // It returns true only when more than half of the states are true.
    const bool motorWasMostlyActive = computeMax(motorStatus);

    std::cout << "Motor was active for most of the test run: "
              << motorWasMostlyActive << '\n';

    return 0;
}
