//element that should be at i, can be at i-1 pr i+1 too

#include<bits/stdc++.h>
using namespace std;

int bin(int arr[],int n,int target)
{
    int start=0;
    int end=n-1;

    while(start<=end)
    {
        int mid=start + (end-start)/2;

        if(arr[mid]==target)
        return mid;

        if(arr[mid-1]==target && mid-1>=start)
        return mid-1;

        if(arr[mid+1]==target && mid+1<=end)
        return mid+1;

        if(target<arr[mid])
        end=mid-2;
        else if(target>arr[mid])
        start=mid+2;
    }
    return -1;
}


int main()
{
    int arr[10]={1,2,3,4,5,7,8,6,9,10};
    int n=10;

    cout<<bin(arr,10,8);
}