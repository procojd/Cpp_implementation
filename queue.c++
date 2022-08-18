#include <iostream>
using namespace std ;

class queue{
    int capacity,rear,front;
    int* Queue;
    queue(int c)
    {
        Queue=new int[c];
        rear=0;
        front=0;
        capacity=c;
    }

    void enqueue(int data)
{
    if(capacity==rear)
    cout<<"queue is full (overflow)";

    else{Queue[rear]=data;
    rear++;}
    
}
void dequeue()
{
    if(front==rear)
    cout<<"queue is empty (underflow)";

    else{Queue[front]=-1;
    front++;
    if(front==rear)
    {
        front=0;
        rear=0;
    }}
    
}

bool isempty()
{
    if(front==rear)
    return true;
    else return false;
}

};

void main()
{

}