#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(string s,int start,int end)
{
    if(start>=end)
    return true;
    return (s[start]==s[end] && ispalindrome(s,start+1,end-1));
}
int main()
{
    string s;
    cin>>s;
    cout<<ispalindrome(s,0,s.length()-1);
    return 0;
}