#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        helper(0,s,ds,ans);
        return ans;
    }

    void helper(int index,string s,
    vector<string>&ds,vector<vector<string>>&ans)
    {
        if(index==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(isPalindrome(s,index,i))
            {
                ds.push_back(s.substr(index,i-index+1));
                helper(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            return false;
        }
        return true;
    }
};