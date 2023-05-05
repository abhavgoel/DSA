#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void helper(int i,string &digits,vector<string>&ans,string &ds,unordered_map<char,string>&m)
{
    if(i>=digits.size())
    {
        ans.push_back(ds);
        return;
    }

    for(auto it:m[digits[i]])
    {
        ds.push_back(it);
        helper(i+1,digits,ans,ds,m);
        ds.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        unordered_map<char,string>m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        vector<string>ans;
        string ds;

        helper(0,digits,ans,ds,m);
        return ans;
    }
};