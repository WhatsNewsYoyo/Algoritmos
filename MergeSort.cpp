#include<iostream>
#include<vector>

using namespace std;

//Merge sort: División, conquista y combina.




void merge(vector<int> &leftArray,vector<int>&rightArray, vector<int>&array){
    int leftSize=leftArray.size();
    int rightSize=rightArray.size();

    //Indices
    int i=0;  //Principal
    int l=0; //Izquierda
    int r=0; //Derecha
    //Main loop donde hace las comparaciones
    while(l<leftSize && r<rightSize){
        if(leftArray[l] < rightArray[r]){
            array[i]=leftArray[l];
            i++;
            l++;
        } else {
            array[i]=rightArray[r];
            i++;
            r++;
        }
    }
    //Copia los elementos restantes de rightArray en arra si los hay

    while(l<leftSize){
        array[i]=leftArray[l];
        i++;
        l++;
    }
    //Copia los elementos restantes de rightArray en arra si los hay
    while(r<rightSize){
        array[i]=rightArray[r];
        i++;
        r++;
    }
}


void mergeSort(vector<int>& array){ //array: size=8
    int n = array.size();
    if(n<=1)return; //caso base
    int center = n/2; //center=4
    //Crear arreglo izquierdo y derecho con el size inicial basado en el lenght
    vector<int> leftArray(center);
    vector<int> rightArray(n-center);
    for(int i= 0; i<n; i++){
        if(i<center){
            leftArray[i]=array[i];
        } else{
            rightArray[i-center]=array[i];
        }
    }
    //Divide
    mergeSort(leftArray);
    mergeSort(rightArray);

    //Conquer
    merge(leftArray, rightArray, array);
    
    //Para unir todos los elementos


}

int main(){
    vector<int> array = {12,3,7,9,14,6,11,2};
    mergeSort(array);
    for(int num:array){
        cout<<num<<" ";
    }

    return 0;
}