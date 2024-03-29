#include<bits/stdc++.h>
using namespace std;
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
    if(dp[index][last]!=-1)return dp[index][last];
    int maxi=-1;

    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            maxi=max(maxi,(points[index][i]) + helper(index-1,i,points,dp));
        }
    }
    return dp[index][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    //return helper(n-1, 3, points,dp);

    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=-1;
    for(int i=0;i<3;i++)
    {
        dp[0][3]=max(dp[0][3],dp[0][i]);
    }

    for(int day=1;day<n;day++ )
    {
        for(int last=0;last<=3;last++)
        {
            dp[day][last]=0;

            for(int task=0;task<3;task++)
            {
                if(task!=last)
                dp[day][last]=max(dp[day][last],
                                (points[day][task]+dp[day-1][task]));
            }
        }

    }
    return dp[n-1][3];
}


//space optimised code

int ninjaTraining1(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4,-1);
   

    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);
    prev[3]=-1;
    for(int i=0;i<3;i++)
    {
        prev[3]=max(prev[3],prev[i]);
    }

    for(int day=1;day<n;day++ )
    {
        vector<int>temp(4,0);
        for(int last=0;last<=3;last++)
        {
            temp[last]=0;

            for(int task=0;task<3;task++)
            {
                if(task!=last)
                temp[last]=max(temp[last],
                                (points[day][task]+prev[task]));
            }
            prev=temp;
        }

    }
    return prev[3];
}