#include<bits/stdc++.h>
using namespace std;

void kthBit(int n,int k)
{
        //method 1 left shift
        if(n&(1<<k-1)!=0)
        cout<<"Yes";
        else cout<<"no";
}
void kthBit1(int n,int k)
{
    //method 2 right shift
    if((n>>(k-1)&1)==1)
    cout<<"yes";
    else cout<<"No";
}

