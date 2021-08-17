#include<bits/stdc++.h>
using namespace std;
//ITERATIVE CODE
int factorial(int n)
{
    int res=1;
    for(int i=2;i<=n;i++)
        res=res*i;
    return res;
}
//recursive code
int fact(int n)
{
    if(n==0)
    return 1;
    return n*fact(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    cout<<fact(n);
    return 0;
}