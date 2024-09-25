#include <iostream>
#include <vector>
using namespace std;


void swap(int& a, int& b){
    int temp = a;
    a=b;
    b=temp;
}

int partition(vector <int>& arr, int low, int high){
  int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j<=high -1; j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
    
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}


void quickSort(vector <int>& arr, int low, int high){

    if (low<high){
      int pivot_location = partition(arr, low, high);
        quickSort(arr, low, pivot_location-1);
        quickSort(arr, pivot_location+1, high);
    } 

}

int main(){
    

    vector<int> arr = {12, 5, 3, 7, 11, 4, 8, 13};
    int n = arr.size();
    int high = n-1;
    int low = 0;

    quickSort(arr, low, high);

    for(int num:arr){
        cout<<num<<" ";
    }
    return 0;
}