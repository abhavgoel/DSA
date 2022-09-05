#include<bits/stdc++.h>
using namespace std;
int lastOcc(int arr[],int x,int n)
{
    int low=0;
    int high=n-1;
    int res=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(x==arr[mid])
        {
            res=mid;
            low=mid+1;
        }
        else if(x<arr[mid])
        high=mid-1;
        else low=mid+1;
    }
    return res;
}
int main()
{
    int arr[10]={1,2,3,4,6,6,6,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter the number to find";
    int x;
    cin>>x;
    cout<<lastOcc(arr,x,n);
}