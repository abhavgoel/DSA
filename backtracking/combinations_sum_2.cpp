#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int index,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans,int sum,int target)
    {
       
             if(target==0)
            {
                ans.push_back(ds);
                  return;
                
            }
            
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            
            ds.push_back(candidates[i]);
            //sum=sum+candidates[i];
            helper(i+1,candidates,ds,ans,sum,target-candidates[i]);
            //sum=sum-candidates[i];
            ds.pop_back();
            
        }
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        
        vector<int>ds;
        helper(0,candidates,ds,ans,0,target);
        return ans;
    }
};