#include<bits/stdc++.h>
using namespace std;
int trailZeroes(int n)
{
    int fact=1;
    for(int i=2;i<=n;i++)
    {
        fact=fact*i;
    }

    int zero=0;
        while(fact%10==0)
        {
            zero++;
            fact=fact/10;
        }
        return zero;

}
//PROBLEM WITH THIS SOLUTION IS OVERFLOW OF DIGITS
int main()
{
    int n;
    cin>>n;
    cout<<trailZeroes(n);
    return 0;
}
//time complexity is theta n