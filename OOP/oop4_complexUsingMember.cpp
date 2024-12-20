#include<iostream>
using namespace std;

class Complex {
public:
    float real;
    float img;

    Complex(float r=0, float i=0) {
        real = r;
        img = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, img + c.img); // (a+c), (b+d)
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, img - c.img); // (a-c), (b-d)
    }

    Complex operator*(const Complex& c) {
        return Complex((real * c.real - img * c.img), // ac-bd
                       (real * c.img + img * c.real)); // ad+bc
    }

    Complex operator/(const Complex& c) {
        float denom = c.real * c.real + c.img * c.img;

        return Complex((real * c.real + img * c.img) / denom, // (ac+bd)/denom
                       (img * c.real - real * c.img) / denom); // (bc-ad)/denom
    }

    void display() const {
        cout << "real : " << real << "\timaginary : " << img << endl;
    }
};

int main() {
    Complex obj1(5, 6);
    Complex obj2(1, 3);

    Complex sum = obj1 + obj2;
    Complex sub = obj1 - obj2;
    Complex mul = obj1 * obj2;
    Complex div = obj1 / obj2;

    cout << "Addition : ";
    sum.display();

    cout << "Subtraction : ";
    sub.display();

    cout << "Multiplication : ";
    mul.display();

    cout << "Division : ";
    div.display();

    return 0;
}