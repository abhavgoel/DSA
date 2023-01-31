#include<bits/stdc++.h>
using namespace std;
void insert(stack<int>&s,int last)
{
    if(s.size()==0 || s.top()>=last)
    {
    s.push(last);
    return;
}

    int val=s.top();
    s.pop();

    insert(s,last);
    s.push(val);


}

void sortstack(stack<int>&s)
{
    if(s.size()==1)
    return;

    int last=s.top();
    s.pop();
    sortstack(s);
    insert(s,last);
    
}


int main()
{
    stack<int> s;
    for(int i=0;i<5;i++)
    {
        int a;
        cin>>a;
        s.push(a);
    }
    sortstack(s);
    while(s.empty()==false)
    {
        int a=s.top();
        s.pop();
        cout<<a<<" ";
    }

}

