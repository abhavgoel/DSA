#include<bits/stdc++.h>
using namespace std;
//element occuring more than n/2 times in a an array
int findMajority(int arr[],int n) //find potential candidate
{
    int res=0;int count =1;
    for(int i=1;i<n;i++)
    {
        if(arr[res]=arr[i])
        count++;
        else count--;
        if(count ==0)
        {
            res=i;
            count =1;

        }
    }
    //check if candidate is actually majority
    count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[res]==arr[i])
        count++;
        if(count<=n/2)
        res=-1;

        return res;


    }
}


