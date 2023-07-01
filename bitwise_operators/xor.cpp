#include<bits/stdc++.h>
using namespace std;

//properties - 

//1^1= 0 
//1^0 = 1
//0^1 = 1
//0^0 = 0

//a^0 = a

// a ^ a = 0


int main()
{
    //if numebr of set bits in A is x, and B is y
    //then number of set bits in A^B is even is x+y is even and odd if x+y is odd

    //lets say A = 1100110001
    //B = 0100110010

    //x = 5, y=4 , x+y = 9
    //then let the number of bits be k that are same in the set bits of A and B
    //then total set bits in A^B is x+y-2*k -->because that bit will be minused from both numbers 


}