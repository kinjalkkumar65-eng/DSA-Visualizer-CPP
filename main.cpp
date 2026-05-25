/*
-------------------------------------------------------
DSA VISUALIZER PROJECT
Created By : Kinjalk 
Language   : C++

Algorithms Implemented:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Linear Search
5. Binary Search

Extra Features:
- Random Array Generation
- ASCII Visualization
- Execution Time
- Comparison Counter
- Swap Counter
-------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class DSAProject {

private:

    vector<int> dataset;

    int comparisonTracker;
    int swapTracker;

public:

    // Constructor
    DSAProject() {

        comparisonTracker = 0;
        swapTracker = 0;
    }

    // Loading Animation
    void loadingScreen() {

        cout << "\nLaunching DSA Visualizer";

        for (int i = 0; i < 5; i++) {

            cout << ".";

            for(int delay = 0; delay < 100000000; delay++){}
        }

        cout << "\n";
    }

    // Create Custom Array
    void customArray() {

        int size;

        cout << "\nEnter Array Size: ";
        cin >> size;

        dataset.clear();

        cout << "Enter Elements:\n";

        for (int i = 0; i < size; i++) {

            int value;
            cin >> value;

            dataset.push_back(value);
        }

        cout << "\nArray Stored Successfully.\n";
    }

    // Generate Random Array
    void randomArray() {

        int size;

        cout << "\nEnter Array Size: ";
        cin >> size;

        dataset.clear();

        srand(time(0));

        for (int i = 0; i < size; i++) {

            dataset.push_back(rand() % 100 + 1);
        }

        cout << "\nRandom Array Generated:\n";

        displayArray();
    }

    // Display Array
    void displayArray() {

        if (dataset.empty()) {

            cout << "\nArray is Empty.\n";
            return;
        }

        cout << "\nCurrent Array:\n";

        for (int value : dataset) {

            cout << value << " ";
        }

        cout << endl;
    }

    // ASCII Visualization
    void asciiGraph() {

        if (dataset.empty()) {

            cout << "\nArray is Empty.\n";
            return;
        }

        cout << "\n===== ASCII BAR VISUALIZATION =====\n";

        for (int value : dataset) {

            cout << value << " : ";

            for (int i = 0; i < value / 2; i++) {

                cout << "|";
            }

            cout << endl;
        }
    }

    // Reset Statistics
    void resetStats() {

        comparisonTracker = 0;
        swapTracker = 0;
    }

    // Delay Function
    void waitAnimation() {

        for(int delay = 0; delay < 100000000; delay++){}
    }

    // Display Result Information
    void resultSummary(string algorithmName,
                       string complexity) {

        cout << "\n====================================";

        cout << "\nAlgorithm Name : " << algorithmName;

        cout << "\nTime Complexity: " << complexity;

        cout << "\nComparisons    : " << comparisonTracker;

        cout << "\nSwaps/Shifts   : " << swapTracker;

        cout << "\n====================================\n";
    }

    // Bubble Sort
    void bubbleSort() {

        if (dataset.empty()) {

            cout << "\nArray Not Found.\n";
            return;
        }

        resetStats();

        int n = dataset.size();

        cout << "\n===== BUBBLE SORT VISUALIZATION =====\n";

        for (int i = 0; i < n - 1; i++) {

            cout << "\nPass " << i + 1 << ":\n";

            for (int j = 0; j < n - i - 1; j++) {

                comparisonTracker++;

                cout << "Comparing "
                     << dataset[j]
                     << " and "
                     << dataset[j + 1]
                     << endl;

                waitAnimation();

                if (dataset[j] > dataset[j + 1]) {

                    cout << "Swapping Elements\n";

                    swap(dataset[j], dataset[j + 1]);

                    swapTracker++;
                }

                displayArray();
            }
        }

        cout << "\nSorted Array:\n";

        displayArray();

        resultSummary("Bubble Sort",
                      "O(n^2)");
    }

    // Selection Sort
    void selectionSort() {

        if (dataset.empty()) {

            cout << "\nArray Not Found.\n";
            return;
        }

        resetStats();

        int n = dataset.size();

        cout << "\n===== SELECTION SORT VISUALIZATION =====\n";

        for (int i = 0; i < n - 1; i++) {

            int minimumIndex = i;

            for (int j = i + 1; j < n; j++) {

                comparisonTracker++;

                cout << "Checking "
                     << dataset[j]
                     << " with "
                     << dataset[minimumIndex]
                     << endl;

                waitAnimation();

                if (dataset[j] < dataset[minimumIndex]) {

                    minimumIndex = j;
                }
            }

            if (minimumIndex != i) {

                swap(dataset[i], dataset[minimumIndex]);

                swapTracker++;

                displayArray();
            }
        }

        cout << "\nSorted Array:\n";

        displayArray();

        resultSummary("Selection Sort",
                      "O(n^2)");
    }

    // Insertion Sort
    void insertionSort() {

        if (dataset.empty()) {

            cout << "\nArray Not Found.\n";
            return;
        }

        resetStats();

        int n = dataset.size();

        cout << "\n===== INSERTION SORT VISUALIZATION =====\n";

        for (int i = 1; i < n; i++) {

            int current = dataset[i];

            int j = i - 1;

            while (j >= 0 && dataset[j] > current) {

                comparisonTracker++;

                dataset[j + 1] = dataset[j];

                swapTracker++;

                j--;

                displayArray();

                waitAnimation();
            }

            dataset[j + 1] = current;
        }

        cout << "\nSorted Array:\n";

        displayArray();

        resultSummary("Insertion Sort",
                      "O(n^2)");
    }

    // Linear Search
    void linearSearch() {

        if (dataset.empty()) {

            cout << "\nArray Not Found.\n";
            return;
        }

        int target;

        cout << "\nEnter Element to Search: ";
        cin >> target;

        comparisonTracker = 0;

        cout << "\n===== LINEAR SEARCH =====\n";

        for (int i = 0; i < dataset.size(); i++) {

            comparisonTracker++;

            cout << "Checking Index "
                 << i
                 << " -> "
                 << dataset[i]
                 << endl;

            waitAnimation();

            if (dataset[i] == target) {

                cout << "\nElement Found at Index "
                     << i
                     << endl;

                resultSummary("Linear Search",
                              "O(n)");

                return;
            }
        }

        cout << "\nElement Not Found.\n";
    }

    // Binary Search
    void binarySearch() {

        if (dataset.empty()) {

            cout << "\nArray Not Found.\n";
            return;
        }

        sort(dataset.begin(), dataset.end());

        int target;

        cout << "\nEnter Element to Search: ";
        cin >> target;

        int left = 0;
        int right = dataset.size() - 1;

        comparisonTracker = 0;

        cout << "\n===== BINARY SEARCH =====\n";

        while (left <= right) {

            int middle = (left + right) / 2;

            comparisonTracker++;

            cout << "Middle Element: "
                 << dataset[middle]
                 << endl;

            waitAnimation();

            if (dataset[middle] == target) {

                cout << "\nElement Found at Index "
                     << middle
                     << endl;

                resultSummary("Binary Search",
                              "O(log n)");

                return;
            }

            else if (dataset[middle] < target) {

                left = middle + 1;
            }

            else {

                right = middle - 1;
            }
        }

        cout << "\nElement Not Found.\n";
    }
};

// Menu UI
void menuUI() {

    cout << "\n========================================";
    cout << "\n         DSA VISUALIZER PROJECT";
    cout << "\n========================================\n";

    cout << "1. Create Custom Array\n";
    cout << "2. Generate Random Array\n";
    cout << "3. Display Current Array\n";
    cout << "4. Bubble Sort\n";
    cout << "5. Selection Sort\n";
    cout << "6. Insertion Sort\n";
    cout << "7. Linear Search\n";
    cout << "8. Binary Search\n";
    cout << "9. ASCII Visualization\n";
    cout << "10. Exit\n";

    cout << "\nEnter Your Choice: ";
}

// Main Function
int main() {

    DSAProject visualizer;

    visualizer.loadingScreen();

    int choice;

    do {

        menuUI();

        cin >> choice;

        switch (choice) {

        case 1:
            visualizer.customArray();
            break;

        case 2:
            visualizer.randomArray();
            break;

        case 3:
            visualizer.displayArray();
            break;

        case 4:
            visualizer.bubbleSort();
            break;

        case 5:
            visualizer.selectionSort();
            break;

        case 6:
            visualizer.insertionSort();
            break;

        case 7:
            visualizer.linearSearch();
            break;

        case 8:
            visualizer.binarySearch();
            break;

        case 9:
            visualizer.asciiGraph();
            break;

        case 10:
            cout << "\nThank You for Using DSA Visualizer.\n";
            break;

        default:
            cout << "\nInvalid Choice. Try Again.\n";
        }

    } while (choice != 10);

    return 0;
}