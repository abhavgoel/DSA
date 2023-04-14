#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int mx=0;

        map<char,int>m;
        while(j<n)
        {
            m[s[j]]++;

            if(m.size()==j-i+1)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(m.size()<j-i+1)//some char is repeating
            {
                while(m.size()<j-i+1)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    m.erase(s[i]);

                    i++;
                    if(m.size()==j-i+1)
                    {
                        mx=max(mx,j-i+1);
                        
                    }

                }
                j++;
            }
        }
        return mx;
    }
};