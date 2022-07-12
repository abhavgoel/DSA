#include<bits/stdc++.h>
using namespace std;
int firstOcc(int arr[],int x,int n)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>x)
        high=mid-1;

        else if(arr[mid]<x)
        low=mid+1;

        else if(arr[mid]==x)
        {
            if(mid==0||arr[mid-1]!=arr[mid])
            return mid;
            else
            {
                high=mid-1;//for case 2,2,2,2,3
            }
        }
    }
    return -1;
}