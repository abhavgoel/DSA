class Solution {
public:
int K;
int SUM;
vector<int>dp;
bool helper(int i,int mask,int sum,int k,vector<int>&nums)
{

    if(k==1)//coz we got k-1 subsets so last would have sum==k
     return true;
    if(dp[mask]!=-1)
    return dp[mask];

    if(sum>SUM)
    return false;
    if(sum==SUM)
    return helper(0,mask,0,k-1,nums);//reset sum to 0;

    

    for(int j=i;j<nums.size();j++)
    {
        if((mask & (1<<j)) || sum + nums[j] > SUM)
        continue;

        mask = mask | (1<<j);
        if(helper(j+1,mask,sum+nums[j],k,nums))
        return dp[mask] = true;
        mask = mask & ~(1<<j);    
        
    }
    return dp[mask] = false;
    
}
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        // vector<int>vis(n);

        int sum  = accumulate(begin(nums),end(nums),0);

        if(sum%k!=0)
        return false;

        sum/=k;
        K=k;
        SUM=sum;
        int mask=0;
        dp.resize(1<<n,-1);
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(0,0,0,k,nums);
    }
};