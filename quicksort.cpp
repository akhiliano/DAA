#include <bits/stdc++.h>
using namespace std;

// Function to perform partition for deterministic quicksort (last element as pivot)
int partitionDeterministic(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic QuickSort function
void quickSortDeterministic(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionDeterministic(arr, low, high);  // Partitioning index

        quickSortDeterministic(arr, low, pi - 1);  // Sort elements before partition
        quickSortDeterministic(arr, pi + 1, high); // Sort elements after partition
    }
}

// Function to perform partition for randomized quicksort
int partitionRandomized(int arr[], int low, int high) {
    // Select a random pivot and swap it with the last element
    int randomPivot = low + rand() % (high - low);
    swap(arr[randomPivot], arr[high]);

    return partitionDeterministic(arr, low, high);  // Proceed as deterministic partition
}

// Randomized QuickSort function
void quickSortRandomized(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionRandomized(arr, low, high);  // Partitioning index

        quickSortRandomized(arr, low, pi - 1);  // Sort elements before partition
        quickSortRandomized(arr, pi + 1, high); // Sort elements after partition
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n], arrCopy[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arrCopy[i] = arr[i];  // Copy array for fair comparison
    }

    // Perform deterministic quicksort
    cout << "\nDeterministic Quick Sort:\n";
    auto startDet = chrono::high_resolution_clock::now();
    quickSortDeterministic(arr, 0, n - 1);
    auto endDet = chrono::high_resolution_clock::now();
    chrono::duration<double> timeDet = endDet - startDet;

    cout << "Sorted array: ";
    printArray(arr, n);
    cout << "Time taken by Deterministic Quick Sort: " << timeDet.count() << " seconds\n";

    // Perform randomized quicksort
    cout << "\nRandomized Quick Sort:\n";
    auto startRand = chrono::high_resolution_clock::now();
    quickSortRandomized(arrCopy, 0, n - 1);
    auto endRand = chrono::high_resolution_clock::now();
    chrono::duration<double> timeRand = endRand - startRand;

    cout << "Sorted array: ";
    printArray(arrCopy, n);
    cout << "Time taken by Randomized Quick Sort: " << timeRand.count() << " seconds\n";

    return 0;
}
