#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]=x)
        return i;
        else return -1;
    }
}