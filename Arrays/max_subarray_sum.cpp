#include<bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int n)
{
    int res=arr[0];
    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            curr=curr+arr[i];
            res=max(res,curr);
        }
    }
    return res;
}

//efficient
int maxSum1(int arr[],int n)
{
    int res=arr[0];
    int maxEnding=arr[0];
    for(int i=0;i<n;i++)
    {
        maxEnding=max(maxEnding+arr[i],arr[i]);
        res=max(res,maxEnding);
    }
   return res;

}