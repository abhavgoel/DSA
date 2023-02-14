#include<bits/stdc++.h>
using namespace std;

void subseq(vector<int>&ds,vector<int>&nums,int index)
{
    if(index==nums.size())
    {
        for(auto i:ds)
        cout<<i<<" ";
        cout<<endl;
        return;
    }

    ds.push_back(nums[index]);
    subseq(ds,nums,index+1);
    ds.pop_back();
    subseq(ds,nums,index+1);
}

int main()
{
    vector<int>nums={3,2,1};
    vector<int>ds;

    subseq(ds,nums,0);
}