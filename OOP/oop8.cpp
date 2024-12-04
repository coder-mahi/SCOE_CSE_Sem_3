// Exception handling --Television 
#include <iostream>
using namespace std;

class Television {
    int modelNumber;
    int screenSize;
    float price;

public:
    Television() : modelNumber(0), screenSize(0), price(0.0f) {}

    friend istream &operator>>(istream &in, Television &tv) {
        cout << "Enter Model Number (4 digits max): ";
        in >> tv.modelNumber;
        if (tv.modelNumber > 9999)
            throw "Model Number exceeds 4 digits.";

        cout << "Enter Screen Size (12-70 inches): ";
        in >> tv.screenSize;
        if (tv.screenSize < 12 || tv.screenSize > 70)
            throw "Screen Size out of valid range.";

        cout << "Enter Price (0-$5000): ";
        in >> tv.price;
        if (tv.price < 0 || tv.price > 5000)
            throw "Price is invalid.";

        return in;
    }

    friend ostream &operator<<(ostream &out, const Television &tv) {
        out << "Model Number: " << tv.modelNumber
            << "\nScreen Size: " << tv.screenSize
            << "\nPrice: $" << tv.price << endl;
        return out;
    }
};

int main() {
    Television tv;

    try {
        cin >> tv;
        cout << "\nTelevision Details:\n" << tv;
    } catch (const char *err) {
        cout << "\nError: " << err << "\n";
        tv = Television(); // Reset to default values
        cout << "\nReset Television Details:\n" << tv;
    }

    return 0;
}
