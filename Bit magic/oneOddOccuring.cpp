//one number will be occuring odd times
//find it
#include<bits/stdc++.h>
using namespace std;
//naive solution
int oddOccuring(int n)
{
    int arr[100];
    for(int i=0;i<n;i++)
    {
        int count =0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;
        }
        if(count%2!=0)
        cout<<arr[i];
    }

}
int oddOccruing2(int arr[],int n)
{
    //by using XOR
    int res=0;
    for (int i=0;i<n;i++)
    {
        res=res^arr[i];

    }
    return res;

}