#include<iostream>
using namespace std;
template<class T>
class Calculator{
    public:
        T num1,num2;
        Calculator(T a,T b){
            num1 = a;
            num2 = b;
        }
        T add(){
            return num1+num2;
        }
        T sub(){
            return num1+num2;
        }
        T mul(){
            return num1*num2;
        }
        T div(){
            return num1/num2;
        }
};
int main(){
    Calculator<int> i(10,20);
    Calculator<float> f(5.2,2.5);
    Calculator<double> d(10.000213,20.432111);
    
    cout<<"Integer : "<<i.add()<<"\t"<<i.sub()<<i.mul()<<"\t"<<i.div()<<endl;
    cout<<"Float : "<<f.add()<<"\t"<<f.sub()<<f.mul()<<"\t"<<f.div()<<endl;
    cout<<"Double : "<<d.add()<<"\t"<<d.sub()<<d.mul()<<"\t"<<d.div()<<endl;
    return 0;
}