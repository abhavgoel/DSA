#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //if the array has even negatives we multiply all the elements provided no 0 is present
        //if array has all positives we multiply all if 0 is absent
        //now if the array has odd negatives and also a 0 then-->
        //think of this like a keeping a breakpoint on every negative and checking its
        //left and right for max product
        //if we encounter our prefix or suffix will be 0 and we can update them to 1 which 
        //implies we are starting for a new subarray eventually creating a breakpoint at 0
        int ans = INT_MIN;
        int prefix=1;
        int suffix=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;

            prefix=prefix * nums[i];
            suffix=suffix * nums[n-i-1];

            ans=max(ans,max(suffix,prefix));
        }
        return ans;
    }
};