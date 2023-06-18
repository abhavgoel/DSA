#include<bits/stdc++.h>
using namespace std

#define ll long long
class Solution {
public:

ll mod = 1e9+7;
vector<vector<ll>>pascal;
    void pascalTriangle(int n)
    {
        pascal.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            pascal[i] = vector<ll>(i+1,1);
            for(int j=1;j<i;j++)
            {
                pascal[i][j] = pascal[i-1][j]%mod + pascal[i-1][j-1]%mod;
            }
            
        }
    }
    int helper(vector<int>&nums)
    {
        ll n = nums.size();

        if(n==1||n==2||n==0)
        return 1;

        vector<int>right,left;
        ll root=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<root)
            left.push_back(nums[i]);

            else
            right.push_back(nums[i]);
        }

        ll x = helper(left)%mod;//getting ans for left subtree
        ll y = helper(right)%mod;//getting value for right subtree

        ll combinations=1;
        if(right.size()!=0)
        combinations = pascal[n-1][right.size()]%mod;//number of ways to arrange the elements

        return (((x*y)%mod)*combinations)%mod;//left*right*arrangements
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascalTriangle(n);//to calculate nCr

        int ans = helper(nums);
        return ans%mod - 1;

    }
};