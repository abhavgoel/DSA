#include<bits/stdc++.h>
using namespace std;
int insert(int arr[],int n,int x,int cap,int pos)
{
    if(n==cap)//cap=capacity of the array
    return n;

    int index=pos-1;
    for(int i=n-1;i>=index;i--)
    {
        arr[i]=arr[i-1];
       
    }
    arr[index]=x;
    return n+1;
}
//time complexity is O(n)
//best case insert at end O(1)
//worst case at beginning theta (n)
/*-------------------------------------------------------------------------*/

//in case of dynamic sized arrays

/*the array is of initially some capacity...then if that capacity is filled then it creates a second array of double
capacity and deallocate the previous one*/
//so average time for inserting at end would be O(1) 