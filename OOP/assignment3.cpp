/* Design a C++ Class ‘Complex ‘ with data members for real and
imaginary part. Provide default and parameterized constructors. Write a
program to perform arithmetic operations of two complex numbers
using operator overloading (using either member functions or friend
functions).*/


#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imaginary;

public:
    Complex() : real(0), imaginary(0) {}
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Operator overloads
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

    // Function to display the complex number
    void display() const {
        cout << real << (imaginary >= 0 ? " + " : " - ") 
                  << abs(imaginary) << "i";
    }
};

int main() {
    Complex c1(4, 5); // 4 + 5i
    Complex c2(2, 3); // 2 + 3i

    cout << "First complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();

    cout << "\n\nSum: ";
    (c1 + c2).display();
    
    cout << "\nDifference: ";
    (c1 - c2).display();

    cout << "\nProduct: ";
    (c1 * c2).display();

    cout << "\nQuotient: ";
    (c1 / c2).display();

    return 0;
}
