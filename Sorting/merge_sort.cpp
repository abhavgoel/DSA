#include<bits/stdc++.h>
using namespace std;

void merge(int low,int mid,int high,vector<int>&arr)
{
    vector<int>temp;
    int left =low;
    int right = mid+1;

    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else 
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];

    }
}
void mergeSort(int low, int high, vector<int>&arr)
{
    if(low==high)
    return;
    
    int mid = (low+high)/2;
    mergeSort(low,mid,arr);
    mergeSort(mid+1,high,arr);

    merge(low,mid,high,arr);

}

int main()
{
    vector<int>arr={5,3,5,7,9,0,5,3,13,7};

    mergeSort(0,arr.size()-1,arr);

    for(auto i:arr)
    cout<<i<<" ";
}