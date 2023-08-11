class Solution {
public:
int final_mask;
vector<vector<int>>dp;
int helper(int time,int mask,int sessionTime,vector<int>&tasks)
{
    if(mask==final_mask)
    {
        return 1;
    }
    if(dp[time][mask]!=-1)
    return dp[time][mask];
    int ans=1e9;
    for(int j=0;j<tasks.size();j++)
    {
        if(mask & (1<<j))continue;

        int pickInThisSession = 1e9;

        if(time+tasks[j]<=sessionTime)
        pickInThisSession = helper(time+tasks[j],mask | (1<<j),sessionTime,tasks);
        //add to current session by increasing the time value by tasks[j]

        int pickInNextSession = 1 + helper(tasks[j], mask | (1<<j),sessionTime,tasks);
        //start a new session with initial value as tasks[j]

        ans=min(ans,min(pickInThisSession,pickInNextSession));
    }
    return dp[time][mask] = ans;
    


}
    int minSessions(vector<int>& tasks, int sessionTime) {
        final_mask = (1<<tasks.size())-1;
        dp.resize(sessionTime+1,vector<int>(1<<tasks.size(),-1));
        return helper(0,0,sessionTime,tasks);

    }
};