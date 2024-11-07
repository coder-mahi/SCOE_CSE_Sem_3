#include<iostream>
using namespace std;
template <class T>
void swap(T x, T y){
    cout<<"Before swapping : X  = "<<x<<", Y = "<<y<<endl;
    T temp = x;
    x = y;
    y = temp;
    cout<<"After swapping : X  = "<<x<<", Y = "<<y<<endl;
}
int main(){
    swap(10,50);
    swap(3.1,5.11);
    swap(2.0004,53.11221);
    swap('a','z');
    return 0;
}