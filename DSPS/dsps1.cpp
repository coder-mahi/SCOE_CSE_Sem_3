// Linear Search
#include<iostream>
using namespace std;

int linearSearch(const int arr[], int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            return i; 
        }
    }
    return -1; 
}
int main(){
    int arr[10];
    int n, el;
    cout<<"Enter Array size :"<<endl;
    cin>>n;
    if(n <= 0 || n > 10){
        cout << "Invalid array size. Please enter a value between 1 and 10." << endl;
        return 1;
    }
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter Search element :"<<endl;
    cin>>el;
    int result = linearSearch(arr, n, el);
    if(result != -1){
        cout << "Element is present at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return 0;
}