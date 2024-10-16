#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    private: 
        int front;
        int rear; //tail queue
        int size;
        int* queue;
    public:
        Queue(int capacity);
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        void dequeue();
        int frontElement();
        ~Queue();

};


#endif //QUEUE_H