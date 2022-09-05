#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int x,int low,int high)//O(n)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        return mid;
        if(arr[mid]>x)
        high=mid-1;
        if(arr[mid]<x)
        low=mid+1;

        
    }
    return -1;
}
int search(int arr[],int x)
{
    int low=0;
    int high=1;
    while(x>arr[high])
    {
        low=high;
        high=high*2;
    }

    cout<<binarySearch(arr,x,low,high);


}