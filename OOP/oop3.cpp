#include <iostream>
using namespace std;
class Complex {
private:
    double real;    
    double imaginary;    

public:
    Complex() {
        real = 0;
        imaginary = 0;
    }
    Complex(double r, double i) {
        real = r;
        imaginary = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imaginary + c.imaginary);
    }
    
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imaginary * c.imaginary,
                       real * c.imaginary + imaginary * c.real);
    }

    Complex operator/(const Complex& c) {
        double denom = c.real * c.real + c.imaginary * c.imaginary;
        return Complex((real * c.real + imaginary * c.imaginary) / denom,
                       (imaginary * c.real - real * c.imaginary) / denom);
    }

    void display() const {
        if (imaginary >= 0)
            cout << real << " + " << imaginary << "i" << endl;
        else
            cout << real << " - " << abs(imaginary) << "i" << endl;
    }
};

int main() {
    Complex c1(4, 5); // 4 + 5i
    Complex c2(2, 3); // 2 + 3i

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "\nSum: ";
    sum.display();

    cout << "Difference: ";
    diff.display();

    cout << "Product: ";
    prod.display();

    cout << "Quotient: ";
    quot.display();
    return 0;
}
