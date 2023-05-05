#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        int i=0;
        int j=0;
        int n = s.size();
        int mn=INT_MAX;
        int idx=0;
        for(auto i:t)m[i]++;

        int count = m.size();

        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                count--;
            }

            if(count>0)
            j++;

            else if(count==0)
            {
                if(j-i+1<mn)
                {
                    mn=j-i+1;
                    idx=i;

                }
                while(count==0 && i<=j)
                {
                    if(m.find(s[i])==m.end())//if not in map we can skip the char and move forward to decrease window size
                    i++;

                    else if(m.find(s[i])!=m.end())
                    {
                        m[s[i]]++;
                        if(m[s[i]]==1)
                        {
                            count++;
                            if(j-i+1<mn)
                            {
                                mn=j-i+1;
                                idx=i;
                            }
                        }   
                        i++;
                    }
                }
                j++;
            }
        }
        cout<<mn;
        if(mn==INT_MAX)return "";
        else return s.substr(idx,mn);
        
    }
};