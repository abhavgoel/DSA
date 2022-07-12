#include<bits/stdc++.h>

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
    if(arr[0]==x)
    return 0;

    int i=1;
    while(arr[i]<x)
    {
        i=i*2;
        
    }
    if(arr[i]==x)
    return i;
    else{
        return binarySearch(arr,x,(i/2)+1,i-1);
    }
}