// Function Template for Selection Sort
#include <iostream>
using namespace std;
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}
// Template Function to Display Array
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArr[] = {10, 500, 3, 2, 6};
    float floatArr[] = {15.12, 50.20, 32, 2.442, 0.6};

    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "Before Sorting Integer Array:\n";
    displayArray(intArr, intSize);

    cout << "Before Sorting Float Array:\n";
    displayArray(floatArr, floatSize);

    // Sorting arrays using function template
    selectionSort(intArr, intSize);
    selectionSort(floatArr, floatSize);

    cout << "\nAfter Sorting Integer Array:\n";
    displayArray(intArr, intSize);

    cout << "After Sorting Float Array:\n";
    displayArray(floatArr, floatSize);

    return 0;
}
