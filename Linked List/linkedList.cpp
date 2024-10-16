#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

};

void addNode(Node* &head, int value){
    Node* newNode = new Node(); //Crear un nuevo nodo en memoria
    newNode -> data = value; //Asignación de value a la estructura accediendo a data
    newNode -> next = nullptr; //El siguiente nodo es nullptr

    if(head == nullptr){
        head = newNode;//Si la lista esta vacia el nuevo nodo es la head
    }
    else{
     Node*   temp = head; //Crea una variable temporal que almacene el current head
     
     //Recoremos la lista hasta el último nodo
     while(temp -> next != nullptr){ 
        temp = temp->next;
     }
        temp->next = newNode; //Enlazamos
    }

}

void showList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" -> "<<endl;
        temp = temp->next;
    }
}

int main(){
    Node* list = nullptr;
    addNode(list, 40);
    addNode(list, 10);
    addNode(list, 890);
    cout<<"Lista de valores: "<<endl;
    showList(list);
    return 0;
}