class Solution {
public:
unordered_set<string>mp;
int helper(int i,string &s,vector<int>&dp)
{
    if(i==s.size())
    return 1;

    if(dp[i]!=-1)
    return dp[i];
    int ways = 0;
    string str="";
    for(int ind = i;ind<s.size();ind++)
    {
        str+=s[ind];
        if(mp.find(str)!=mp.end())
        {
            ways+=helper(ind+1,s,dp);
        }
        else return dp[i] = ways;
    }
    return dp[i] =  ways;


}
    int numDecodings(string s) {
        

        for(int i=1;i<=26;i++)
        {
            mp.insert(to_string(i));
        }
        vector<int>dp(s.size(),-1);
        return helper(0,s,dp);
    }
};