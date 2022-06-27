#include<bits/stdc++.h>
using namespace std;
int* insertX(int n, int arr[],
            int x, int pos)
{
    int i;
 
    // increase the size by 1
    n++;
 
    // shift elements forward
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
 
    // insert x at pos
    arr[pos - 1] = x;
 
    return arr;
}
//time complexity is O(n)
//best case insert at end O(1)
//worst case at beginning theta (n)
/*-------------------------------------------------------------------------*/

//in case of dynamic sized arrays

/*the array is of initially some capacity...then if that capacity is filled then it creates a second array of double
capacity and deallocate the previous one*/
//so average time for inserting at end would be O(1) 
