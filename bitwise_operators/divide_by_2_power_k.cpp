#include<bits/stdc++.h>
using namespace std;

int main()
{
    //when we divide  a number by 2,
    //its binary representation is weighted sum of powers of 2,
    //so we are shifting it to right , to reduce every factor by 2

    int x = 6;
    //110;

    int k = 1;
    //divide by 2^k --> x>>k
    int y = x>>k;
    cout<<y;
}