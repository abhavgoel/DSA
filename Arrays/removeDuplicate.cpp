#include<bits/stdc++.h>
using namespace std;
int remDups(int arr[],int n)
{
    int temp[n];
    temp[0]=arr[0];//coz the first element would be same even if it is repeating 
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(temp[res-1]!=arr[i])
        {
            temp[res]=arr[i];
            res++;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=temp[i];
    }
    return res;//size of new array

}
//O(n) time and space

//efficient solution

int remDups1(int arr[],int n)
{
    int res=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[res-1])
        {
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}
//O(n) time and space