#include <bits/stdc++.h>
using namespace std;

// not for repeating characters
const int CHAR = 256;
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

int lexrank(string s)
{
    int n = s.length();
    int mul = fact(n);
    int res = 0;
    int count[CHAR] = {0};

    for (int i = 0; i < n; i++)
    {
        count[s[i]]++;
    }

    for (int i = 1; i < CHAR; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        mul = mul / (n - i);
        res = res + count[s[i] - 1] * mul;

        for (int j = s[i]; j < CHAR; j++)
        {
            count[j]--;
        }
    }
    return res + 1;
}
int main()
{
    string s = "dabc";
    cout << lexrank(s);
}