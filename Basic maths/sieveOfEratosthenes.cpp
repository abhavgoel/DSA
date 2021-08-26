#include<bits/stdc++.h>
using namespace std;
//simple implementation
void sieve(int n)
{
    vector<bool> isPrime(n+1,true);
    for(int i=2;i*i<=n;i++)
    {
        if (isPrime[i])
        {
            for (int j=j*i;j<=n;j=j+i)
            {
                isPrime[j]=false;

            }
        }

    }
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        cout<<i<<endl;
    }
}
