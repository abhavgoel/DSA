#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int index,vector<int>nums,vector<int>&ds,vector<vector<int>>&ans)
    {
        ans.push_back(ds);
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            helper(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        helper(0,nums,ds,ans);
        return ans;
    }
};