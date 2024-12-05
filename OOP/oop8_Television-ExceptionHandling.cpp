// 8. Television --Exception Handling Updated
#include <iostream>
using namespace std;
class Television {
public:
    int model_no, size, price;
    friend istream &operator>>(istream &in, Television &t) {
        in >> t.model_no >> t.size >> t.price;
        if (t.model_no > 9999) {
            throw 1;
        }
        if (t.size < 12 || t.size > 70) {
            throw 2;
        }
        if (t.price < 0 || t.price > 5000) {
            throw 3;
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, const Television &t) {
        out << "\nModel Number: " << t.model_no
            << "\nSize: " << t.size << " inches"
            << "\nPrice: $" << t.price;
        return out;
    }
    void reset() {
        model_no = 0;
        size = 0;
        price = 0;
    }
};
int main() {
    Television t;
    try {
        cout << "Enter the Model Number, Size (in inches), and Price of the Television: ";
        cin >> t;
        cout << t;
    } catch (int i) {
        cout << "\nException occurred: ";
        if (i == 1) {
            cout << "Invalid Model Number (must be 4 digits or less).";
        } else if (i == 2) {
            cout << "Invalid Size (must be between 12 and 70 inches).";
        } else if (i == 3) {
            cout << "Invalid Price (must be between $0 and $5000).";
        }
        t.reset();
        cout << "\nResetting Television details to default values:" << t;
    }
    return 0;
}
