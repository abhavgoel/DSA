#include<bits/stdc++.h>
using namespace std;
bool isPow1(int n)//naive solution

{
    if(n==0)
    return false;
    while(n!=1)
    {
        if(n%2!=0)
        return false;
        n=n/2;

    }
    return true;
}
//efficient solution by brian kerningam algo
bool isPow2(int n)
{
    if(n==0) //or 1 line expression as return (n!=0)&&((n&(n-1))==0);
    return false;
    else 
    return ((n&(n-1))==0);
    //as power of two only has 1 bit ...so by brian kerningam the bits after that 1 bit are reversed and the & operator is used and we should get 0
    //eg 4-->100
    //3-->011
}