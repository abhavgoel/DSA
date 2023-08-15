#include<bits/stdc++.h>
using namespace std;

int partition(int low,int high,vector<int>&arr)
{
    int pivot = arr[low];
    int i = low;
    int j =high;


    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)//finding first largest element from left and swapping it from first smallest element in right part
        {
            i++;
        }
        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;

}
void quickSort(int low, int high,vector<int>&arr)
{
    if(low<high)
    {
        int partitionInd = partition(low,high,arr);
        quickSort(low,partitionInd-1,arr);
        quickSort(partitionInd+1,high,arr);
    }
}

int main(){
    vector<int>arr={4,5,6,8,4,3,1,2,43,5,63};
    quickSort(0,arr.size()-1,arr);

    for(auto i:arr)
    cout<<i<<" ";
    return 0;
}