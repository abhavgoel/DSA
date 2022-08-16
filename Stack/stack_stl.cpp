#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.size();
    cout<<endl;
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top();


while(s.empty()==false)
{
    cout<<s.top()<<endl;
    s.pop();
}

}//all have O(1) complexity