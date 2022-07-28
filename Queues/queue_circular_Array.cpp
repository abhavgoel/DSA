#include<bits/stdc++.h>
using namespace std;
//using circular array
struct Queue
{
    int capacity;
    int size;
    int front;
    int *arr;
    Queue(int c)
    {
        capacity=c;
        size=0;
        front =0;
        arr = new int[c];
    }

    bool isFull()
    {
    return capacity==size;
    }

    bool isEmpty()
    {
        return size==0;
    }

    int getFront()
    {
        if(isEmpty())
        return -1;

        else 
        return front;
    }
    int getRear()
    {
        if(isEmpty())
        return -1;

        else
        {
            return (front+size-1)%capacity;
        }
    }

    void enque(int x)
    {
        if(isFull())
        return;

        int rear=getRear();
        rear=(rear+1)%capacity;
        arr[rear]=x;
        size++;
    }
    void deque()
    {
        if(isEmpty())
        return;

        front=(front+1)%capacity;
        size--;
    }



}; 

int main()
{
    Queue q(10);
    q.enque(1);
    q.enque(2);
   // q.deque();
    cout<<q.getFront()<<" ";
    cout<<q.getRear();

}