class Solution {
public:

//when its ur chance do your f*cking best,
//when its your opponent's chance expect the worst
int helper(int i,int j,int turn , vector<int>&nums,vector<vector<int>>&dp)
{
    //we calculate the p1-p2 score in this code
    if(i>j)
    return 0;
   
    if(dp[i][j]!=-1)
    return dp[i][j];

    if(turn==1)
    {
        int a = nums[i] +  helper(i+1,j,0,nums,dp);//maximizing score for p1
        int b = nums[j] + helper(i,j-1,0,nums,dp);

        return dp[i][j] = max(a,b);
    }
    else 
    {
        int a = -nums[i] + helper(i+1,j,1,nums,dp);//minimizing the score for p1
        int b = -nums[j] + helper(i,j-1,1,nums,dp);
        return dp[i][j] = min(a,b);
    }
    return 0;
    
}
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int p1 = helper(0,nums.size()-1,1,nums,dp);
        return p1>=0;
    }
};