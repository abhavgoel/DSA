#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void helper(int open,int close,string s,vector<string>&ans)
{
    if(open==0&&close==0)
    {
    ans.push_back(s);
    return;
    }

    if (open!=0)
    {
        s.push_back('(');
        helper(open-1,close,s,ans);
        s.pop_back();
    }

    if(close>open)
    {
        s.push_back(')');
        helper(open,close-1,s,ans);
        s.pop_back();
    }



}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=n;
        int close=n;
        string s="";
        helper(open,close,s,ans);
        return ans;
    }
};