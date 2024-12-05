// 8. Television --Exception Handling
#include <iostream>
using namespace std;

class Television {
    int modelNumber;
    int screenSize;
    float price;

public:
    Television() : modelNumber(0), screenSize(0), price(0.0f) {}

    void inputDetails() {
        cout << "Enter Model Number (4 digits max): ";
        cin >> modelNumber;
        if (modelNumber > 9999) throw "Model Number exceeds 4 digits.";

        cout << "Enter Screen Size (12-70 inches): ";
        cin >> screenSize;
        if (screenSize < 12 || screenSize > 70) throw "Screen Size out of valid range.";

        cout << "Enter Price (0-$5000): ";
        cin >> price;
        if (price < 0 || price > 5000) throw "Price is invalid.";
    }

    void displayDetails() const {
        cout << "Model Number: " << modelNumber
             << "\nScreen Size: " << screenSize
             << "\nPrice: $" << price << "\n";
    }
};

int main() {
    Television tv;

    try {
        tv.inputDetails();
        cout << "\nTelevision Details:\n";
        tv.displayDetails();
    } catch (const char *err) {
        cout << "\nError: " << err << "\n";
        cout << "\nReset Television Details:\n";
        tv.displayDetails(); // Default values remain.
    }

    return 0;
}
