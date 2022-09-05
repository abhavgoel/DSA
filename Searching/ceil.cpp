#include<bits/stdc++.h>
using namespace std;

int ceil(vector<int>nums,int target)
{
    int n=nums.size();
    int res=-1;

    int start=0;
    int end=n-1;

    while(start<=end)
    {
        int mid=start + (end-start)/2;

        if(nums[mid]>target)
        {
            res=mid;
            end=mid-1;
        }
        else if(nums[mid]<target)
        {
            start=mid+1;
        }
    }
}

