#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v = {1,3,4,3,2,4,5,2,12,3,13,4,21};

    cout<<lower_bound(begin(v),end(v),10) - begin(v);
    return 0;
}