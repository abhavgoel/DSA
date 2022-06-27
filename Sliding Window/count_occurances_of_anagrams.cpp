#include<bits/stdc++.h>
using namespace std;

int countOcc(string x,string s)
{
    int ans=0;
    map<char,int> m;
    for(auto i:x)
    {
        m[i]++;
    }
    int i=0,j=0;
    int k=x.size();
    int count=m.size();
    while(j<s.size())
    {
        if(m.find(s[j])!=m.end())
        {
            m[s[j]]--;
            if(m[s[j]]==0)
            count--;

        }
        

        if(j-i+1<k)
        j++;

        else if(j-i+1==k)
        {
            if(count==0)
            ans++;


        
        if(m.find(s[i])!=m.end())
        {
            m[s[i]]++;
            if(m[s[i]]==1)
            count++;
        }
        i++;
        j++;
        }
    }
    
    return ans;
}
int main()
{
    string x ="aaba";
    string s="aabaabaa";
    cout<<countOcc(x,s);
}