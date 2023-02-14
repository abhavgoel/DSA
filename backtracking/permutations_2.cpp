#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&ans,int index,set<vector<int>>&s)
    {
        if(index==nums.size())
        {
            s.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            helper(nums,ans,index+1,s);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        helper(nums,ans,0,s);
        for(auto i:s)
        {
            ans.push_back(i);
        }
        
        return ans;
        
    }
};