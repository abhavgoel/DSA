#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s,int x)
{
    if(s.size()==0)
    s.push(x);
    else 
    {
        int temp=s.top();//pushing the element to bottom os stack by 
        //popping all elements and inserting the element to bottom
        s.pop();
        insert(s,x);
        s.push(temp);
    }
}

void reverse(stack<int> &s)
{
    if(s.size()==1)
        return;
    
    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s,temp);//pushing to last of stack
}
