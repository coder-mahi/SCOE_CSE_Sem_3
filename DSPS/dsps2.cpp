#include <iostream>
using namespace std;

// 1. Function to sort the array in descending order
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// 2. Function to copy book costs less than 500 into a new array
int copyCostsLessThan500(int arr[], int n, int newArr[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 500) {
            newArr[count] = arr[i];
            count++;
        }
    }
    return count;  // Return the number of books copied
}

// 3a. Delete duplicate entries using a temporary array
int removeDuplicatesWithTemp(int arr[], int n, int newArr[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < count; j++) {
            if (arr[i] == newArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            newArr[count] = arr[i];
            count++;
        }
    }
    return count;  // Return new size after removing duplicates
}

// 3b. Delete duplicate entries without using a temporary array
int removeDuplicatesWithoutTemp(int arr[], int n) {
    int newSize = n;
    for (int i = 0; i < newSize - 1; i++) {
        for (int j = i + 1; j < newSize; j++) {
            if (arr[i] == arr[j]) {
                // Shift all elements to the left
                for (int k = j; k < newSize - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                newSize--;
                j--;  // Adjust index after deletion
            }
        }
    }
    return newSize;  // Return new size after removing duplicates
}

// 4. Function to count books with cost greater than 500
int countBooksGreaterThan500(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 500) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    int bookCosts[n];
    cout << "Enter the costs of the books (in ascending order): ";
    for (int i = 0; i < n; i++) {
        cin >> bookCosts[i];
    }

    // 1. Sort the array in descending order
    sortDescending(bookCosts, n);
    cout << "Book costs in descending order: ";
    for (int i = 0; i < n; i++) {
        cout << bookCosts[i] << " ";
    }
    cout << endl;

    // 2. Copy book costs less than 500 into a new array
    int costsLessThan500[n];
    int countLessThan500 = copyCostsLessThan500(bookCosts, n, costsLessThan500);
    cout << "Books with costs less than 500: ";
    for (int i = 0; i < countLessThan500; i++) {
        cout << costsLessThan500[i] << " ";
    }
    cout << endl;

    // 3a. Remove duplicates using a temporary array
    int noDuplicatesTemp[n];
    int newSizeTemp = removeDuplicatesWithTemp(bookCosts, n, noDuplicatesTemp);
    cout << "Books costs after removing duplicates (using temp array): ";
    for (int i = 0; i < newSizeTemp; i++) {
        cout << noDuplicatesTemp[i] << " ";
    }
    cout << endl;

    // 3b. Remove duplicates without using a temporary array
    int newSize = removeDuplicatesWithoutTemp(bookCosts, n);
    cout << "Books costs after removing duplicates (without temp array): ";
    for (int i = 0; i < newSize; i++) {
        cout << bookCosts[i] << " ";
    }
    cout << endl;

    // 4. Count books with cost greater than 500
    int countGreaterThan500 = countBooksGreaterThan500(bookCosts, n);
    cout << "Number of books with cost greater than 500: " << countGreaterThan500 << endl;

    return 0;
}
