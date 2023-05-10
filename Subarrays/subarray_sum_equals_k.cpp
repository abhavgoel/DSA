#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//---------------------brute force-----------------------------
    // int subarraySum(vector<int>& nums, int k) {
    //     int count=0;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         int sum=0;
    //         for(int j=i;j<nums.size();j++)
    //         {
    //             sum+=nums[j];
    //             if(sum==k)
    //             count++;
    //         }
    //     }
    //     return count;
    // }

    int subarraySum(vector<int>& nums, int k) {
        //the idea is to calculate prefix sum at each point and if previously we encountered
        //prefixsum-k we add its count to the result
        
        
        unordered_map<int,int>mp;
        int count=0;
        int prefixsum=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++)
        {
            prefixsum+=nums[i];
            
            count=count + mp[prefixsum-k];

            mp[prefixsum]++;
        }
        return count;
    }
};