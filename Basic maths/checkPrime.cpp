#include<bits/stdc++.h>
using namespace std;
//first method time complexity O(n)
bool isPrime(int n)
{
    if(n==1)
    return false;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        return false;
        
    }
}

//second time complexity O(n^1/2)

// if(x,y) is dividing pair of n
//x*y=n;
//if x<=y,,then x*x<=n....x<n^1/2
//so we run loop till n^1/2
bool isPrime1(int n)
{
   if(n==1)
   return false;
   for(int i=2;i*i<=n;i++)
   {
       if(n%i==0)
       return false;
       
   } 
}

//more efficient solution for large n

bool isPrime3(int n)
{
    if(n==1) return false;
    if(n==2||n==3) return true;
    if(n%2||n%3==0) return false;
    for (int i=5;i*i<=n;i=i+6)
    {
        if(n%i==0||n%(i+2)==0)
        return false;
       
    }
}