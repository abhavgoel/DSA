#include<bits/stdc++.h>
using namespace std;
//maintain 2 pointers so that enque operation doesnt takes O(n) time
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct Queue
{
    Node *front;
    Node *rear;
    int size;
    Queue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }

    void enque(int x)
    {
        Node *temp= new Node(x);
        size++;
        if(front==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void deque()
    {
        if(front==NULL)
        return;
        size--;
        Node* temp=front;
        front=front->next;
        if(front==NULL)
        rear=NULL;
        delete temp;
    }
    int getFront()
    {
        return front->data;

    }
    int getRear()
    {
        return rear->data;

    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.deque();

    cout<<"size"<< " "<<q.getSize()<<endl;

    cout<<"front "<<q.getFront()<<endl;

    cout<<"rear "<<q.getRear()<<endl;
}