class Solution {
public:
int ans =   INT_MIN;
    void helper(int i,vector<int>&indegree,vector<vector<int>>&requests,int count)
    {
        if(i==requests.size())
        {
            for(int j=0;j<indegree.size();j++)
            {
                if(indegree[j]!=0)return;
            }
            ans = max(ans,count);
            return; 
        }

        indegree[requests[i][0]]--;
        indegree[requests[i][1]]++;
        helper(i+1,indegree,requests,count+1);
        indegree[requests[i][0]]++;
        indegree[requests[i][1]]--;
        helper(i+1,indegree,requests,count);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>indegree(n,0);
        helper(0,indegree,requests,0);

        return ans;

    }
};