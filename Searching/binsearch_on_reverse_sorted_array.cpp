#include<bits/stdc++.h>
using namespace std;

int  binsearch(int arr[],int low,int high,int target)
{
    while(low<=high)
    {
        int mid=low + (high-low)/2;

        if(arr[mid]==target)
        return mid ;
        
        else if(arr[mid]>target)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}

int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the number to find";
    int x;
    cin>>x;
    cout<<binsearch(arr,0,9,x);
}