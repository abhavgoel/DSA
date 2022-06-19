#include<bits/stdc++.h>
using namespace std;
void leaders(int a[],int n)//no element greater on right side of it
{
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        for(int j=i+1;j<n;j++)
        {
            if(a[i]<=a[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            cout<<a[i]<<" ";
        }
    }
}

//efficient solution
//traverse from right side , if current elemnt greater than current leader then its also a leader
void leaders1(int a[],int n)
{
    int curr_ldr=a[n-1];
    cout<<curr_ldr<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>curr_ldr)
        {
            curr_ldr=a[i];
            cout<<curr_ldr<<" ";
        }
    }
}