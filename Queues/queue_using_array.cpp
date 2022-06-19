#include<bits/stdc++.h>
using namespace std;
int main()
{
    struct Queue
    {
        int size,cap;
        int *arr;
        Queue(int c)
        {
            cap=c;
            size=0;
            arr=new int[cap];
        }
        void enque(int x)
        {
            if(isFull())
            return;
            arr[size]=x;
            size++;
        }
        void deque(int x)
        {
            if (isEmpty())
            return;
            for(int i=0;i<size-1;i++)
            {
                arr[i]=arr[i+1];
            }
            size--;
        }
        int getFront() //return index of first element
        {
            if(isEmpty())
            return -1;
            else return 0;
        }
        int getRear()//return index of last element
        {
            if (isEmpty())
            return -1;
            else return size-1;
        }
        bool isFull()
        {
            return (size==cap);
        }
        bool isEmpty()
        {
            return (size==0);
        }
        int size()
        {
            return size;
        }

    };
    return 0;
}