#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//     void helper(int index, vector<vector<int>>&ans,vector<int>&ds,vector<int>&candidates,int target)
//     {
//         if(index==candidates.size())
//         {
//             if(target==0)
//             {
//                 ans.push_back(ds);
//             }
//             return ;
//         }
        
//         if(candidates[index]<=target)
//         {
//             ds.push_back(candidates[index]);
//             helper(index,ans,ds,candidates,target-candidates[index]);
//             ds.pop_back();
//         }
//         helper(index+1,ans,ds,candidates,target);
//     }
    
    void helper2(int index, vector<vector<int>>&ans,vector<int>&ds,vector<int>&candidates,int target,int sum)
    {
        if(index==candidates.size())
        {
            if(sum==target)
            ans.push_back(ds);
            return;
        }
        if(index>candidates.size() || sum>target)return;
        
        ds.push_back(candidates[index]);
        sum=sum+candidates[index];
        helper2(index,ans,ds,candidates,target,sum);//completing calls with same index first
        sum=sum-candidates[index];
        ds.pop_back();
        helper2(index+1,ans,ds,candidates,target,sum);
            
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        helper2(0,ans,ds,candidates,target,0);
        return ans;
    }
};