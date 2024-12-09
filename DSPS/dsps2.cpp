// #include <iostream>
// using namespace std;

// // 1. Function to sort the array in descending order
// void sortDescending(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] < arr[j]) {
//                 // Swap arr[i] and arr[j]
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// // 2. Function to copy book costs less than 500 into a new array
// int copyCostsLessThan500(int arr[], int n, int newArr[]) {
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < 500) {
//             newArr[count] = arr[i];
//             count++;
//         }
//     }
//     return count;  // Return the number of books copied
// }

// // 3a. Delete duplicate entries using a temporary array
// int removeDuplicatesWithTemp(int arr[], int n, int newArr[]) {
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         bool isDuplicate = false;
//         for (int j = 0; j < count; j++) {
//             if (arr[i] == newArr[j]) {
//                 isDuplicate = true;
//                 break;
//             }
//         }
//         if (!isDuplicate) {
//             newArr[count] = arr[i];
//             count++;
//         }
//     }
//     return count;  // Return new size after removing duplicates
// }

// // 3b. Delete duplicate entries without using a temporary array
// int removeDuplicatesWithoutTemp(int arr[], int n) {
//     int newSize = n;
//     for (int i = 0; i < newSize - 1; i++) {
//         for (int j = i + 1; j < newSize; j++) {
//             if (arr[i] == arr[j]) {
//                 // Shift all elements to the left
//                 for (int k = j; k < newSize - 1; k++) {
//                     arr[k] = arr[k + 1];
//                 }
//                 newSize--;
//                 j--;  // Adjust index after deletion
//             }
//         }
//     }
//     return newSize;  // Return new size after removing duplicates
// }

// // 4. Function to count books with cost greater than 500
// int countBooksGreaterThan500(int arr[], int n) {
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > 500) {
//             count++;
//         }
//     }
//     return count;
// }

// int main() {
//     int n;
//     cout << "Enter the number of books: ";
//     cin >> n;

//     int bookCosts[n];
//     cout << "Enter the costs of the books (in ascending order): ";
//     for (int i = 0; i < n; i++) {
//         cin >> bookCosts[i];
//     }

//     // 1. Sort the array in descending order
//     sortDescending(bookCosts, n);
//     cout << "Book costs in descending order: ";
//     for (int i = 0; i < n; i++) {
//         cout << bookCosts[i] << " ";
//     }
//     cout << endl;

//     // 2. Copy book costs less than 500 into a new array
//     int costsLessThan500[n];
//     int countLessThan500 = copyCostsLessThan500(bookCosts, n, costsLessThan500);
//     cout << "Books with costs less than 500: ";
//     for (int i = 0; i < countLessThan500; i++) {
//         cout << costsLessThan500[i] << " ";
//     }
//     cout << endl;

//     // 3a. Remove duplicates using a temporary array
//     int noDuplicatesTemp[n];
//     int newSizeTemp = removeDuplicatesWithTemp(bookCosts, n, noDuplicatesTemp);
//     cout << "Books costs after removing duplicates (using temp array): ";
//     for (int i = 0; i < newSizeTemp; i++) {
//         cout << noDuplicatesTemp[i] << " ";
//     }
//     cout << endl;

//     // 3b. Remove duplicates without using a temporary array
//     int newSize = removeDuplicatesWithoutTemp(bookCosts, n);
//     cout << "Books costs after removing duplicates (without temp array): ";
//     for (int i = 0; i < newSize; i++) {
//         cout << bookCosts[i] << " ";
//     }
//     cout << endl;

//     // 4. Count books with cost greater than 500
//     int countGreaterThan500 = countBooksGreaterThan500(bookCosts, n);
//     cout << "Number of books with cost greater than 500: " << countGreaterThan500 << endl;

//     return 0;
// }



#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; // Define MAX_BOOKS globally

class Lib {
public:
    int cost;
    string name;

    void info() {
        cout << "Enter name of book: ";
        cin.ignore(); // Clear the buffer before reading a line
        getline(cin, name);
        cout << "Enter cost of book: ";
        cin >> cost;
    }

    // Static method to display all books
    static void displayAll(Lib books[], int n) {
        cout << "\tName\tCost\n";
        for (int i = 0; i < n; ++i) {
            cout << "\t" << books[i].name << "\t" << books[i].cost << "\n";
        }
    }

    // Static method to sort books in descending order by cost
    static void sortDescending(Lib books[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (books[i].cost < books[j].cost) {
                    // Swap
                    Lib temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }

    // Static method to display books with cost less than 500
    static void displayCostLessThan500(Lib books[], int n) {
        for (int i = 0; i < n; ++i) {
            if (books[i].cost < 500) {
                cout << "\t" << books[i].name << "\t" << books[i].cost << "\n";
            }
        }
    }
    
    // Static method to display number of books with cost more than 500
    static void displayCostMoreThan500(Lib books[], int n) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (books[i].cost > 500) {
                ++count;
            }
        }
        cout << "Number of books greater than 500: " << count << endl;
    }

    // Static method to delete duplicate entries based on the name only in the original array
    static void deleteDuplicate(Lib books[], int& n) {
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n) {
                if (books[j].name == books[i].name) {
                    // Shift all elements to the left
                    for (int k = j; k < n - 1; ++k) {
                        books[k] = books[k + 1];
                    }
                    --n; // Reduce the total count
                } else {
                    ++j;
                }
            }
            ++i;
        }
        cout << "\nDuplicates removed based on book name in the original array.\n";
        cout << "Unique books after removing duplicates:" << endl;
        displayAll(books, n);
    }
    
    // Static method to delete duplicate entries using a temporary array without modifying the original array
    static void deleteduplicatetemp(const Lib books[], int n) {
        Lib tempBooks[MAX_BOOKS];
        int tempCount = 0;

        for (int i = 0; i < n; ++i) {
            bool isDuplicate = false;
            for (int j = 0; j < tempCount; ++j) {
                if (books[i].name == tempBooks[j].name) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                tempBooks[tempCount++] = books[i];
            }
        }

        cout << "\nDuplicates removed using temporary array.\n";
        cout << "Unique books from the temporary array:" << endl;
        displayAll(tempBooks, tempCount);
    }
};

int main() {
    Lib books[MAX_BOOKS];
    int n = 0;  // Initialize number of books to 0
    int i, ch, choice;

    do {
        cout << "\n1. Insert data\n2. Display data\n3. Sort in descending order\n4. Display books with cost less than 500\n5. Display number of books with cost more than 500\n6. Delete duplicate entries in original array\n7. Delete duplicate entries with temporary array\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter number of books: ";
                cin >> n;
                if (n > MAX_BOOKS) {
                    cout << "Number of books exceeds the maximum limit of " << MAX_BOOKS << endl;
                    n = MAX_BOOKS;  // Limit the number of books to MAX_BOOKS
                }
                for (i = 0; i < n; ++i) {
                    books[i].info();
                }
                break;
            case 2:
                cout << "\tName\tCost\n";
                Lib::displayAll(books, n);
                break;
            case 3:
                Lib::sortDescending(books, n);
                cout << "Books sorted in descending order:" << endl;
                Lib::displayAll(books, n);
                break;
            case 4:
                cout << "Books with cost less than 500:" << endl;
                Lib::displayCostLessThan500(books, n);
                break;
            case 5:
                Lib::displayCostMoreThan500(books, n);
                break;
            case 6:
                Lib::deleteDuplicate(books, n);
                break;
            case 7:
                Lib::deleteduplicatetemp(books, n);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        if (ch != 1) {
            cout << "\nEnter 1 to continue, 0 to exit: ";
            cin >> choice;
        } else {
            choice = 1;  // Automatically continue if data was just entered
        }
    } while (choice == 1);

    return 0;
}