#include<bits/stdc++.h>
using namespace std;
int lcm(int a,int b)
{
    int res=max(a,b);
    while(true)
    {
        if(res%a==0&&res%b==0)
        {
            return res;
        }
        else res++;
    }
}

//more efficient way

    // a*b=gcd(a,b)*lcm(a,b)

int gcd(int a,int b)
{
    if(b==0)
    return a;
    else 
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
//time complexity is log(min(a,b))

