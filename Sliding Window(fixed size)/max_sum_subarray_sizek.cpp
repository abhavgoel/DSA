#include<bits/stdc++.h>
using namespace std;

int slidingWindow(int arr[],int n,int k)
{
    int sum=0;
    int mx=INT_MIN;
    int i,j=0;
    while (j<n)
    {
        sum+=arr[j];//calc
        if(j-i+1<k)
        j++;
        else if(j-i+1==k)
        {
            //ans
            mx=max(mx,sum);
            sum=sum-arr[i];//slide window
            i++;
            j++;
        }
    }
    return mx;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<slidingWindow(arr,n,k);
}