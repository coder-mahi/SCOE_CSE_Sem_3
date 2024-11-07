#include<iostream>
using namespace std;
template<typename T>
class Show{
    public:
    T *arr;
    int n;
    T key;
    Show(T array[],int n1,T k){
        arr = array;
        n = n1;
        key = k;
    }
    void search(){
        bool found = false;
        for(int i = 0; i < n; i++){
            if(arr[i]==key){
                found = true;
                cout<<"Element found at pos : "<<i;
                break;
            }
        }
        if(found == false){
            cout<<"Not Found .."<<endl;
        }
    }
};
int main(){
    int arr[] = {10,20,30,40,50};
    int s = 5;
    int key = 20;
    Show<int> obj(arr,s,key);
    obj.search();
    return 0;
}