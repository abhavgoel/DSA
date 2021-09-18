#include<bits/stdc++.h>
using namespace std;
//first find the index of the largest element
int getLargest(int arr[],int n)
{
    int largest=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            largest=i;

        }
    }
    return largest;
}
int secondLargest(int arr[],int n)
{
    int largest=getLargest(arr,n);
    int res=-1;//if all the number are equal then index should be returned as -1
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[largest])
        {
            if(res==-1)
            res=i;

             else if(arr[i]>arr[res])
            res=i;
        }
    }
    return res;
}
int main()
{
    int arr[5]={10,10,10,10,10};
    cout<<secondLargest(arr,5);
    return 0;
}

//effective approach
int secondLargest1(int arr[],int n)
{
    int res=-1,largest=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            res=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest])
        {
            if(res==-1||arr[i]>arr[res])
            {
                res=i;
            }
        }
    }
    return res;
}