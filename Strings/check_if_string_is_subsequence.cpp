#include<bits/stdc++.h>
using namespace std;

//total subsequence is string of length n - 2^n

bool isSubseq(string n,string m,int nn,int mm)
{
    int j=0;
    for(int i=0;i<nn&&j<mm;i++)
    {
        if(n[i]==m[j])
        j++;
    }
    return (j==mm);
}