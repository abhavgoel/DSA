//maintain order of other elements
#include<bits/stdc++.h>
using namespace std;
//naive solution
void moveToEnd(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]!=0)
                {
                    swap(a[i],a[j]);
                }
            }
        }
    }
}
//efficient 
void moveZeroes(int a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            swap(a[i],a[count]);
            count++;
        }
    }
}