#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 6;
    //110

    int y = x | (1<<0);
    cout <<y ;//should be 7 as we set the 0th bit
}