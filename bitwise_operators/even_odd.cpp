#include<bits/stdc++.h>
using namespace std;

//LSB IS 1 if the number is odd
//LSB is 0 if the number is even

/*
example - 
binary(9) = 1001
LSB of this no. will be '1' because it's an odd number
binary(10) = 1010
LSB of this no. will be '0' because it's a even number
*/

int main()
{
    int x = 9;
    int y = 10;

    if(y&1)cout<<"odd\n";
    else cout<<"even\n";
}