#include<bits/stdc++.h>
using namespace std;

int countSubSeq(int index ,vector<int>&nums,int s,int sum)
{
    if(index==nums.size())
    {
        if(s==sum) return 1;
        
        else return 0;
    }

    s=s+nums[index];

    int l = countSubSeq(index+1,nums,s,sum);

    s=s-nums[index];

    int r = countSubSeq(index+1,nums,s,sum);
    return l+r;
}

int main()
{
    vector<int>nums={1,2,1};
    int sum=2;
    cout<<countSubSeq(0 ,nums,0, sum);
    
}