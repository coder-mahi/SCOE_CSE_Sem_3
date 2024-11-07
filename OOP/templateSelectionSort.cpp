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
        // for(int i=0;i<size-1;i++){
        //     for(int j=i+1;j<size;j++){
        //         if(arr[j]<arr[i]){
        //             T temp = arr[j];
        //             arr[j] = arr[i];
        //             arr[i] = temp;
        //         }
        //     }
        // }
        for(int i=0;i<size-1;i++){
            int minIndex = i;
            for(int j=i+1;j<size;j++){
                if(arr[j]<arr[minIndex]){
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
    int arr1[] = {10,500,3,2,6};
    float arr2[] = {15.12,50.20,32,2.442,0.6};
    
    SelectionSort<int> obj1(arr1,5);
    SelectionSort<float> obj2(arr2,5);
    cout<<"Integer Array :"<<endl;
    obj1.display();
    obj1.sort();
    obj1.display();
    cout<<"\nFloating Point Array :"<<endl;
    obj2.display();
    obj2.sort();
    obj2.display();
    return 0;
  }