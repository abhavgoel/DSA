#include<bits/stdc++.h>
using namespace std;
//when we subtract 1 from a number the bits after the first set bit gets reversed including the first bit from right
//eg 40-->101000
//32-->100111
int countBits(int n)
{
    int res=0;
    while(n>0);
    {
        n=(n&(n-1));
        res++;
    }
    return res;
    //time complexity = theta(total set bits)
}