#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void selectionSort(vector <int> &vec){
    int n=vec.size();

    for (int i = 0; i<n-1; i++){
        int minVal=i;
        for(int j = i+1; j<n;j++){
            if (vec[j]<vec[minVal]){
                minVal=j;
            }
        }
        if (minVal !=i){
            swap(vec[i], vec[minVal]);
        }
    }
}


int main(){
    vector <int> vec = {2,18,33,3,10};
    selectionSort(vec);
    for(int num:vec){
        cout<<num<<" ";
    }
    return 0;
}



void swap(int& a, int& b){
    int temp = a;
    a=b;
    b=temp;
}