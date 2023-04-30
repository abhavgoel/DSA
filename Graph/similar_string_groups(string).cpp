#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isValid(string &s,string &p)
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=p[i])
        cnt++;
    }
    return (cnt==0 || cnt==2);//if only two places to be swapped
}
void dfs(int node,vector<int>&vis,vector<string>&strs)
{
    vis[node]=1;
    for(int i=0;i<strs.size();i++)
    {
        if(vis[i]==0)
        {
            if(isValid(strs[node],strs[i]))
            {
                dfs(i,vis,strs);
            }
        }
    }
}
    int numSimilarGroups(vector<string>& strs) {
        int count=0;
        int n=strs.size();
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(i,vis,strs);
            }
        }
        return count;
    }
};