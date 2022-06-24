#include<bits/stdc++.h>
using namespace std;

int maxConsOne(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==1)
            curr++;
            else break;
        }
        res=max(res,curr);
    }
    return res;
}

int maxCons1(int arr[],int n)
{
     int curr=0;
     int res=0;
    for(int i=0;i<n;i++)
    {
       
        if(arr[i]==0)
        curr=0;
        else
        {
            curr++;
            res=max(res,curr);
        }
    }
    return res;
}