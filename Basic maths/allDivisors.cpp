#include<bits/stdc++.h>
using namespace std;
void printDivisors(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i;
            if(i!=n/i)
            cout<<n/i;
        }
    }
}

//to print in ascending order
void printDivisors1(int n)
{
    int i;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i;
        }
    }
    for( ;i>=1;i--)
    {
        if(n%i==0)
        cout<<n/i;
    }
} 