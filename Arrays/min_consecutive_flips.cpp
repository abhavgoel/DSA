//Minimum Consecutive Flips
//Given a binary array, we need to find the minimum of number of group flips to make all array elements same.  
//In a group flip, we can flip any set of consecutive 1s or 0s.
#include<bits/stdc++.h>
using namespace std;

void printGroups(bool arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            if(arr[i]!=arr[0])
            {
                cout<<"from "<<i<<" to";
                

            }
            else cout<<i-1<<endl;
        }
    }
    if(arr[n-1]!=arr[0])
    cout<<n-1<<endl;//last number case

}