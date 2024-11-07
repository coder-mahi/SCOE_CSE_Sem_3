#include<iostream>
using namespace std;
class shape
{
    public:
    virtual void calculateArea()=0;
};
class traingle:public shape{
    public:
    float len,bre;
    traingle(float l,float b){
        len=l;
        bre=b;
    }
    void calculateArea(){
        cout<<"\nArea of traingle is: "<<0.5*len*bre;
    }
};
class circle:public shape{
    public:
    float r;
    circle(float rad){
        r=rad;
    }
    void calculateArea(){
        cout<<"\nArea of circle is:"<<3.14*r*r;
    }
};
int main(){
    traingle t(1.2,3.4);
    t.calculateArea();
    circle c(2.3);
    c.calculateArea();
    return 0;
}