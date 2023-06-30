#include<bits/stdc++.h>
using namespace std;
//if we want to check if kth bit is set or not we set kth kit as 1 in a number and take of it from the original number
/*
example - 
x = 100010101100
check 4th bit is set of not(from right)

so we'll just take AND of the number from 2^k - which is nothing but 1 set on kth position

eg - 2^k where k=4 = 000010000 - 1 set at kth position
*/
int main()
{
    //check if kth bit is set or not
    int x = 6;// 110
    //check if first bit is set or not
    if(x & (1<<1))
    cout<<"set";
    else cout<<"not set";
}