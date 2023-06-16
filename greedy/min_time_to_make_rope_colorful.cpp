#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //update the max of same colors everytime while iterating
        int time= 0 ;
        int prevMax=0;
        for(int i=0;i<colors.size();i++)
        {
            if(i>0&&colors[i]!=colors[i-1])
            {
                prevMax=0;
            }
            time = time + min(neededTime[i],prevMax);
            prevMax = max(prevMax,neededTime[i]);
        }
        return time;
    }
};