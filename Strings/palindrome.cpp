#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    //using two pointer approach

    int begin=0;
    int end=s.length()-1;
    while(begin<end)
    {
        if(s[begin]!=s[end])
        return false;

        begin++;
        end--;
    }
    return true;
}