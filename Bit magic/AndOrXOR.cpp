#include<bits/stdc++.h>
using namespace std;

//bitwise AND & --> 1&1=1, rest cases 0
//bitwise OR  | --> 0|0=0, rest cases 1
//bitwise XOR ^ --> produces 1 if bits are different and 0 is bits are same

int main()
{
    int x=3,y=6;
    cout<<(x&y)<<endl;
    cout<<(x|y)<<endl;
    cout<<(x^y)<<endl;
    return 0;
}