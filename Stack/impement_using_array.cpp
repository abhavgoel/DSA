#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int *arr;
    int capacity;
    int top;

    Stack(int x)
    {
        capacity=x;
        arr=new int[capacity];
        top=-1;
    }

    void push(int x)
    {
        if(top==capacity-1)
        {
            cout<<"stack overflow..cant push "<<x<<endl;
            return;
        }
        
        top++;
        arr[top]=x;

    }

    int pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return 0;
        }
        int res=arr[top];
        top--;
        return res;
    }
    int peek()
    {
    return arr[top];
    }
    int size()
    {
        return top+1;
    }
    bool isEmpty()
    {
        return (top==-1);
    }

};
int main()
{
    Stack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}