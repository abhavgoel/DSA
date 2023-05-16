#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>&nums)
{
    int n=nums.size();
        vector<int>lis;

        for(int i=0;i<n;i++)
        {
            int ind = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();

            if(ind ==lis.size())
            lis.push_back(nums[i]);
            else
            lis[ind]=nums[i];
        }
        return lis.size();
}