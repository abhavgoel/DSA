#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 6;
    int y = 8;

    //swap

    x = x^y; //x = x^y , y=y
    y=x^y;// x=x^y, y = (x^y)^y = x
    x=x^y;// x = (x^y)^x = y , y = x
    cout<<x<<" "<<y;
}