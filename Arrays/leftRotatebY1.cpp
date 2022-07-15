#include<bits/stdc++.h>
using namespace std;
void lRotateOne(int a[],int n)
{
    int temp=a[0];
    for(int i=1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    a[n-1]=temp;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

int main()
{
    int arr[10]={1,3,4,5,6,7};
    int n=6;
    lRotateOne(arr,n);

}