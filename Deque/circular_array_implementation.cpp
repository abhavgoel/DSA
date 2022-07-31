#include<bits/stdc++.h>
using namespace std;

struct Deque
{
    int *arr;
    int front,capacity,size;
    Deque(int c)
    {
        capacity=c;
        front=0;
        size=0;
        arr=new int[capacity];
    }
     bool isFull()
    {
        return (size==capacity);
    }
    bool isEmpty()
    {
        return size==0;
    }
    void deleteFront()
    {
        if(isEmpty())
        {
            return;
        }
        front=(front+1)%capacity;
        size--;
    }

    void insertRear(int x)
    {
        if(isFull())
        return;

        int new_rear=(front+size)%capacity;
        arr[new_rear]=x;
        size++;
    }

    int getFront()
    {
        if(isEmpty())
        return -1;

        else return front;
    }

    void insertFront(int x)
    {
        if(isFull())
        return;
        front=(front-1+capacity)%capacity;
        arr[front]=x;
        size++;

    }

    void deleteRear()
    {
        if(isEmpty())
        return;

        size--;
    }
    int getRear()
    {
        if(isEmpty())
        return;

        else return (front+size-1)%capacity;
    }



};