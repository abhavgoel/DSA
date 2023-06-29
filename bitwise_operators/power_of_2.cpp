#include<bits/stdc++.h>
using namespace std;
/*
binary(16) = 10000
binary(15) = 01111
if we take AND and asn is 0 , THEN ITS A POWER OF 2
*/
int main()
{
    int x = 16;
    if((x&(x-1))==0)
    cout<<"power of 2"<<endl;
}