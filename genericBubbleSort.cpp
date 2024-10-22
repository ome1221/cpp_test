#include <iostream>
using namespace std;


template<typename dataType>
void bubbleSort(dataType arr[], int n) {
    // Loop through all elements of the array
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place, so no need to check them
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                dataType temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template<typename dataType>
void printArray(dataType arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: \n";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}
