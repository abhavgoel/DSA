#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    // your code here
    map<char,int>m;
    int i=0;
    int j=0;
    int n = s.length();
    int mx=-1;
    while(j<n)
    {
        m[s[j]]++;
        if(m.size()<k)
        j++;
        
        else if(m.size()==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        
        else if(m.size()>k)
        {
            while(m.size()>k)
            {
                m[s[i]]--;
                
                if(m[s[i]]==0)
                m.erase(s[i]);
                
                i++;
                
                if(m.size()==k)
                mx=max(mx,j-i+1);
            }
            
            
            j++;
        }
    }
    return mx;
    }