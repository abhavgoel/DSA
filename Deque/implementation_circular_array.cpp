#include<bits/stdc++.h>
using namespace std;

struct Deque
{
    int size,capacity;
    int *arr;

    Deque(int c)
    {
        capacity=c;
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
    void insertRear(int x)
    {
        if(isFull())
        return;

        arr[size]=x;
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
        return -1;

        else return (size-1);
    }

    void insertFront(int x)
    {
        if(isFull())
        return;

        for(int i=size-1;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=x;
        size++;
    }
    void deleteFront()
    {
        if(isEmpty())
        return;

        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];

        }
        size--;

    }
    int getFront()
    {
        if(isEmpty())
        return;
        else return 0;
    }

};