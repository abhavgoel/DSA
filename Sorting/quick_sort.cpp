#include<bits/stdc++.h>
using namespace std;
int countt=0;
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
            countt++;
        }
        while(arr[j]>pivot && j>=low+1)
        {
            j--;
            countt++;
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
    vector<int>arr={4,1,5,3,2};
    quickSort(0,arr.size()-1,arr);

    for(auto i:arr)
    cout<<i<<" ";
    cout<<endl;
    cout<<countt;
    return 0;
}