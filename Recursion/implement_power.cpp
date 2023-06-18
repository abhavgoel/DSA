#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
long long power(int R, int n)
{
    if(n==0)return 1;
    
    long long temp = power(R,n/2);
    if(n%2==0)
    return (temp%mod*temp%mod)%mod;
    else return ((temp%mod*temp%mod)%mod*R%mod)%mod;
}
int nthTermOfGP(int N, int A, int R) {
   //a,ar,ar^2

   long long x = power(R,N-1)%mod;

   return (A%mod*x%mod)%mod;
   
}
//trick is to use temp = power(R,n/2) and use temp, else we habve to recall fucntion everytime 
