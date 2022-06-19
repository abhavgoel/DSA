#include<bits/stdc++.h>
using namespace std;
//1st solution
void leftRotate(int a[],int n,int d)
{
    int temp[n];
    for(int i=0;i<d;i++)
    {
        temp[i]=a[i];
    }
    for(int i=d;i<n;i++)
    {
        a[i-d]=a[i];
    }
    for(int i=0;i<d;i++)
    {
        a[n-d+i]=temp[i];
    }
}

//second solution
void reverse(int a[],int low,int high)
{
    while(low<high)
    {
        swap(a[low],a[high]);
        low++;
        high--;
    }
}

void leftRotate1(int a[],int n,int d)
{
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(a)/sizeof(a[0]);
    leftRotate(a,n,3);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}