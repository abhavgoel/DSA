#include<bits/stdc++.h>
using namespace std;
//naive solution
bool isSorted(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]<arr[i])
            return false;
            else return true;
        }
    }
    
}

//efficient solution
bool isSorted1(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        return false;
        else return true;
    }
}
