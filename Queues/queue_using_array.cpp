#include<bits/stdc++.h>
using namespace std;

//using array
struct Queue
{
    int  size;
    int capacity;
    int *arr;

    Queue(int c)
    {
        capacity=c;
        size=0;
        arr=new int[capacity];
    }
    bool isFull()
    {
        return  size==capacity;
    }
    bool isEmpty()
    {
        return size==0;
    }

    void enque(int x)
    {
        if(isFull())
        return;

        arr[size]=x;
        size++;
        
    }

    void deque() // takes O(n) time
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
        return -1;

        else return 0;  //index of first element
    }

    int getRear()
    {
        if(isEmpty())
        return -1;
        else return size-1;
    }

};



int main()
{
    

}