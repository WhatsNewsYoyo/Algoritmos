#include <iostream>
using namespace std;

#include "Queue.h"

int main(){

    
    Queue q(5);
    q.enqueue(10);
    q.enqueue(50);
    q.enqueue(34);

    q.dequeue();
    q.dequeue();

    cout<<"El front element es: "<< q.frontElement()<<endl;
    

    return 0;
}