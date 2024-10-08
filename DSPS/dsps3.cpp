#include <iostream>
#include <algorithm>  // For sorting in binary search
using namespace std;

// Linear Search function
bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return true;  // Student found
        }
    }
    return false;  // Student not found
}

// Binary Search function
bool binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return true;  // Student found
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;  // Student not found
}

int main() {
    int n, rollNumber;
    int students[n];

    cout << "Enter the number of students who attended the training program: ";
    cin >> n;
    cout << "Enter the roll numbers of students: ";
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    cout << "Enter the roll number to search: ";
    cin >> rollNumber;

    if (linearSearch(students, n, rollNumber)) {
        cout << "Student attended the training program (Linear Search)." << endl;
    } else {
        cout << "Student did NOT attend the training program (Linear Search)." << endl;
    }

    // Sorting array for Binary Search
    sort(students, students + n);

    if (binarySearch(students, n, rollNumber)) {
        cout << "Student attended the training program (Binary Search)." << endl;
    } else {
        cout << "Student did NOT attend the training program (Binary Search)." << endl;
    }

    return 0;
}
