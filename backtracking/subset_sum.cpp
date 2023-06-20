#include<bits/stdc++.h>
using namespace std;

//sum of all subsets

void helper(int index,vector<int>arr,vector<int>&ans,int sum)
{
    if(index==arr.size())
    {
        ans.push_back(sum);
        return;
    }
    helper(index+1,arr,ans,sum+arr[index]);
    helper(index+1,arr,ans,sum);
    
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>ans;
        helper(0,arr,ans,0);
        sort(ans.begin(),ans.end());
        return ans;
    }