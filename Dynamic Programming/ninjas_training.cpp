#include<bits/stdc++.h>
using namespace std;

//ninja-is-planing-this-n-days-long-training-schedule
//-each-day-he-can-perform-any-one-of-these-three-activities-
//running-fighting-practice-or-learning-new-moves-each-activity-
//has-some-merit-points-on-each-day-as-ninja-has-to-improve-all-
//his-skills-he-can-t-do-the-same-activity-in-two-consecutive-
//days-can-you-help-ninja-find-out-the-maximum-merit-points-ninja-can-earn
int helper(int index,int last, vector<vector<int>>&points,vector<vector<int>>&dp)
{
    if(index==0)
    {
        int maxi=-1;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[index][last]!=-1)return dp[index][last]; //memoizations
    int maxi=-1;

    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            maxi=max(maxi,(points[index][i]) + helper(index-1,i,points,dp));
        }
    }
    return dp[index][last] = maxi;//memoization
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return helper(n-1, 3, points,dp);
}