#include<bits/stdc++.h>
using namespace std;

int getsum(int n)
{
    if(n==0)
    return 0;
    else return n%10 + getsum(n/10);
}
