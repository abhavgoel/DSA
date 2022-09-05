#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int x,int n)//O(n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+ (high-low)/2; //to prevent overflow
        if(arr[mid]==x)
        return mid;
        if(arr[mid]>x)
        high=mid-1;
        if(arr[mid]<x)
        low=mid+1;

        
    }
    return -1;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the number to find";
    int x;
    cin>>x;
    cout<<binarySearch(arr,x,n);
}