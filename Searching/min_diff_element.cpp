#include<bits/stdc++.h>
using namespace std;

// min of floor and ceil of the target

int minDiff(vector<int> nums,int target)
{
    int start=0;
    int end=nums.size()-1;

    while(start<=end)
    {
        int mid=start+(end-start)/2;

        if(nums[mid]==target)
        return (nums[mid]-target);

        else if(nums[mid]>target)
        {
            end=mid-1;

        }
        else start=mid+1;
    }
    return min(nums[start]-target,nums[end]-target);
}