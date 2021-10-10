#include<bits/stdc++.h>
using namespace std;
int deleteEle(int arr[],int n,int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        break;

    }
    if(i==n)//if not present in the array
    return n;
    for(int j=i;j<n-1;j++)//loop
    {
        arr[j]=arr[j+1];
        
    }
    return (n-1);

}