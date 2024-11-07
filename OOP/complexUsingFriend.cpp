#include<iostream>
using namespace std;
class Complex{
    public:
    float real;
    float img;
    Complex(float r=0, float i=0){
        real = r;
        img = i;
    }
    friend Complex operator+(const Complex& c1,const Complex& c2);
    friend Complex operator-(const Complex& c1,const Complex& c2);
    friend Complex operator*(const Complex& c1,const Complex& c2);
    friend Complex operator/(const Complex& c1,const Complex& c2);
    void display() const{
        cout<<"real : "<<real<<"\timaginary : "<<img<<endl;
    }
};
Complex operator+(const Complex& c1,const Complex& c2){
    return Complex(c1.real+c2.real,c1.img+c2.img);
}
Complex operator-(const Complex& c1,const Complex& c2){
    return Complex(c1.real-c2.real,c1.img-c2.img);
}
Complex operator*(const Complex& c1,const Complex& c2){
    return Complex((c1.real*c1.img - c2.real*c2.img),       // abcd
                    (c1.real*c2.img + c1.img*c2.real));     // adbc
}
Complex operator/(const Complex& c1,const Complex& c2){
    float denom = (c2.real*c2.real,c2.img*c2.img);
    return Complex((c1.real*c2.real + c2.img*c1.img)/denom,     //acdb
                    (c1.img*c2.real - c1.real*c2.img)/denom);   //bcad
}
int main(){
    Complex obj1(5,6);
    Complex obj2(1,3);
    Complex sum = obj1+obj2;
    Complex sub = obj1-obj2;
    Complex mul = obj1*obj2;
    Complex div = obj1/obj2;
    cout<<"Addition : ";
    sum.display();
    cout<<"Subration : ";
    sub.display();
    cout<<"Multiplication : ";
    mul.display();
    cout<<"Division : ";
    div.display();
    return 0;
}