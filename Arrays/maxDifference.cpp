#include<bits/stdc++.h>
using namespace std;

int maxDiff(int a[],int n)
{
    int res=a[1]-a[0];
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res=max(res,a[j]-a[i]);
        }
    }
    return res;
}

//efficient
int maxDiff1(int a[],int n)
{
    int res =a[1]-a[0];
    int minVal=a[0];
    for(int j=1;j<n;j++)
    {
        res = max(res,a[j]-minVal);
        minVal = min(minVal,a[j]);
    }
    return res;

}