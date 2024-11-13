#include<iostream>
using namespace std;
template<typename T>
class SelectionSort{
    public:
    T *arr;
    int size;
    SelectionSort(T array[],int n){
        arr = array;
        size = n;
    }
    void sort(){
        for(int i=0;i<size-1;i++){
            int minIndex = i;
            for(int j=i+1;j<size;j++){
                if(arr[j]<minIndex){
                    minIndex = j;
                }
            }
            if(minIndex!=i){
                T temp = arr[minIndex];
                arr[minIndex] = arr[i];
                arr[i] = temp; 
            }
        }
    }
     void display(){
        for(int i =0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int a1[100];
    int s;
    cout<<"Enter size of array :"<<endl;
    cin>>s;    
    for(int i=0;i<s;i++){
        cin>>a1[i];
    }
    SelectionSort<int> obj(a1,s);
    cout<<"Before :"<<endl;
    obj.display();
    cout<<"After :"<<endl;
    obj.sort();
    obj.display();
    return 0;
}