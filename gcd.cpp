#include<bits/stdc++.h>
using namespace std;
//we can also use gcd to find the side of largerst square to fill the whole rectangle axb
int gcd(int a, int b)
{
    int res=min(a,b);
    while(res>0)
    {
        if(a%res==0&&b%res==0)
        break;
        
        else
        res--;
        
    }
    return res;
}
//time complexity is O(min(a,b))...worst case
int main()

{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
