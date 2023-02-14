#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//     void helper(vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums,vector<int>&freq)
//     {
//         if(ds.size()==nums.size())
//         {
//             ans.push_back(ds);
//             return;
//         }
        
//         for(int i=0;i<nums.size();i++)
//             {
//                 if(freq[i]==0)
//                 {
//                 ds.push_back(nums[i]);
                
//                 freq[i] = 1;
//                 helper(ds,ans,nums,freq);
//                 ds.pop_back();
//                 freq[i]=0;
//                 }
//             }
//     }
    
    void helper(vector<int>&nums,vector<vector<int>>&ans,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            helper(nums,ans,index+1);
            swap(nums[index],nums[i]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>freq(n);
        // vector<int>ds;
        vector<vector<int>>ans;
        helper(nums,ans,0);
        return ans;
        
        
    }
};