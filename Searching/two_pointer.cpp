#include<bits/stdc++.h>
using namespace std;
//find a pair with given sum
bool isPair(int arr[],int left,int right,int sum)
{
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    
    while(left<right)
    {
        if(arr[left]+arr[right]==sum)
        return true;

        else if(arr[left]+arr[right]>sum)
        right--;
        else left++;
    }
    return false;
}

//find a pair with given sum
bool isTriplet(int arr[],int sum,int n)
{
    for(int i=0;i<n;i++)
    {
        if(isPair(arr,i+1,n-1,sum-arr[i]))
        return true;
    }
    return false;
}