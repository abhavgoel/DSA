#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int n,int x)
{
    int high=n-1;
    int low=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
        {
            return mid;
        }
        if(arr[low]<arr[mid])
        {
            //left array is sorted
            if(x>=arr[low]&&x<arr[mid])
            {
                //element present in left half
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            //right half sorted
            if(x>arr[mid] && x<=arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;
}
//or find min element in roatetd array and do bin search on both sides of it and return the positive ans