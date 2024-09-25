#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(vector <int> & vec, int j, int i){
    int const temp = vec[j];
    vec[j]=vec[i];
    vec[i]=temp;
}


void bubbleSort(vector <int> & vec){
    int n = vec.size();
    for(int i =0; i<n; i++){
        for(int j=0; j<n -1-i; j++ ){
            if(vec[j]>vec[j+1]){
                swap(vec, j, j+1);
            }
        }
    }
}

int main() {
    vector <int> vec;
    bubbleSort(vec);
    for(int num: vec){
        cout<<num;
    }

    int calificaciones=7;
    int valor;

    for (int i=0; i<calificaciones;i++){
        cout<<"Ingresa el valor de la calificacion"<<endl;
        cin>>valor;
        vec.push_back(valor);
    }
    bubbleSort(vec);
    for  (int i: vec){
        cout<<i<<" ";
    }
    cout<<endl;


    auto max= max_element(vec.begin(), vec.end());
    int maxima=*max;
    cout<<"el valor mas grande es: "<<maxima<<endl;

    auto min= min_element(vec.begin(), vec.end());
    int minima=*min;
    cout<<"el valor mas chico es: "<<minima<<endl;

    return 0;
}