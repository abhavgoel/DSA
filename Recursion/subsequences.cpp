#include<bits/stdc++.h>
using namespace std;

void subseq(int index,vector<vector<int>>&ans,vector<int>&arr,vector<int>&nums)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }

    arr.push_back(nums[index]);
    subseq(index+1,ans,arr,nums);
    arr.pop_back();
    subseq(index+1,ans,arr,nums);


}
int main()
{
    vector<int>nums={3,1,2};
    vector<vector<int>>ans;
    vector<int>arr;
    subseq(0,ans,arr,nums);
    
    
}