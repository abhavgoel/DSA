#include<bits/stdc++.h>
using namespace std;
int sliding(int arr[],int n,int k)//max subarray sum with given length k
{
    int curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
    }   
    int max_sum=curr_sum;
    for(int i=k;i<n;i++)
    {
        curr_sum+=arr[i]-arr[i-k];
        max_sum=max(max_sum,curr_sum);
    }
    return max_sum;

}


