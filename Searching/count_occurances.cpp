#include<bits/stdc++.h>
#include "index_of_first_occurence.cpp"
#include "index_of_last_occurance.cpp"

using namespace std;

int countOcc(int arr[],int x,int n)
{
    int first = firstOcc(arr,x,n);
    if(first==-1)
    return 0;
    else return (lastOcc(arr,x,n)-first+1);
}