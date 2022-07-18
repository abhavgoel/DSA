#include<bits/stdc++.h>
using namespace std;

//O(n^3)
bool areDistinct(string s,int i,int j)
{
    vector<bool> v(256);
    for(int k=i;k<=j;k++)
    {
        if(v[s[k]]==true)
        return false;

        v[s[k]]=true;
    }
    return true;
}
int longestSubstr(string s)
{
    int n=s.length();
    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(areDistinct(s,i,j))
            res=max(res,j-i+1);

        }
    }
    return res;
}

//O(n^2)

int longestSubstr1(string s)
{
    int n=s.length();
    int res=0;
    for(int i=0;i<n;i++)
    {
        vector<bool> v(256);
        for(int j=i;j<n;j++)
        {
            if(v[s[j]]==true)
            break;

            else
            {
                v[s[j]]=true;
                res=max(res,j-i+1);
            }
        }
        
    }
    return res;
}

//O(n)

int longestSubstr2(string s)
{
    int left=0;
    int right=0;
    int len=0;
    int n=s.length();
    vector<int> m(256,-1);
    while(right<n)
    {
        if(m[s[right]]!=-1)
        left=max(m[s[right]]+1,left);

        m[s[right]]=right;
        len=max(len,right-left+1);
        right++;
    }
    return len;

}
int main() 
{ 
	string str = "geeksforgeeks"; 
	int len = longestSubstr2(str); 
	cout << "The length of the longest distinct characters substring is "<< len; 
	return 0; 
} 
