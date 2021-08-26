#include<bits/stdc++.h>
using namespace std;
//naive solution
void primeFactors() //O(n^2logn)
{
    for(int i=2;i<n;i++)
    {
        if(isPrime(i))
        {
            int x=i;
            while(n%x==0)
            {
                cout<<i;
                x=x*i;
            }
        }
    }
}

//efficient solution
void printPrimeFactors(int n)
{
    if(n<=1)
    return;
    for (int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i;
            n=n/i;
        }
    }
    if(n>1)
    cout<<n;
}
