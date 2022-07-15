#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string ss)
{
    if (s.length() != ss.length())
        return false;
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
        m[ss[i]]--;
    }
    for (auto i : m)
        if (i.second != 0)
            return false;

    return true;
}
int main()
{
    string s;
    cin >> s;
    string ss;
    cin >> ss;
    cout << isAnagram(s, ss);
}