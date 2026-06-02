#include <iostream>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[4]  = {7, 3, 9, 4};
    int n       = 4;

    int comparisons = 0;
    int swaps       = 0;

    std::cout << "Startarray: ";
    printArray(arr, n);
    std::cout << std::endl;

    // Selection Sort setzt in jeder Runde den kleinsten Wert an die richtige Stelle.
    for (int i = 0; i < n - 1; i++)
    {
        // minIndex speichert die Position des kleinsten Werts, den wir bisher gefunden haben.
        int minIndex = i;

        // Suche im unsortierten Rest des Arrays nach einem kleineren Wert. (j = i + 1)
        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            std::cout << "Vergleich " << comparisons << ": "<< arr[j] << " mit " << arr[minIndex]
            << std::endl;

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Nur tauschen, wenn der kleinste Wert nicht schon an Position i steht.
        if (minIndex != i)
        {
            int temp        = arr[i];
            arr[i]          = arr[minIndex];
            arr[minIndex]   = temp;

            swaps++;

            std::cout << "Tausch " << swaps << ": Position "
                 << i + 1 << " <-> " << minIndex + 1 << std::endl;
        }
        else
        {
            std::cout << "Kein Tausch in Runde " << i + 1 << std::endl;
        }

        std::cout << "Array nach Runde " << i + 1 << ": ";
        printArray(arr, n);
        std::cout << std::endl;
    }

    std::cout << "Fertig sortiert: ";
    printArray(arr, n);

    std::cout << "Anzahl Vergleiche: " << comparisons << std::endl;
    std::cout << "Anzahl Tausche: " << swaps << std::endl;

    return 0;
}
