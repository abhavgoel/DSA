#include<bits/stdc++.h>
using namespace std;

//inverts all bits i.e 0 to 1 and 1 to 0

int main()
{
    unsigned int x=1;
    cout<<(~x)<<endl;
    x=5;
    cout<<~x<<endl;

    //signed input (-2^31 to 2^31 -1)
    //if MSB is 1 the number is negative
    int y=1;
    cout<<~y<<endl;//using 2's compliment----> 2^n-y....where n is number of bits mostly 32....and 2^32-1 =1111.....1(32 times)......2^32-1-x
    return 0;


}