#include<bits/stdc++.h>
using namespace std;

void subseqSumK(int index,vector<int>&ds,vector<int>&nums,int s,int sum)
{
    if(index==nums.size())
    {
        if(s==sum)
        {
            for(auto i:ds)cout<<i<<" ";
            cout<<endl;
            
        }
        return;
    }

    ds.push_back(nums[index]);
    s=s+nums[index];
    subseqSumK(index+1,ds,nums,s,sum);
    s=s-nums[index];
    ds.pop_back();
    subseqSumK(index+1,ds,nums,s,sum);
}

int main()
{
    vector<int>nums={2,5,2,1,2};
    vector<int>ds;
    int sum =5 ;
    subseqSumK(0,ds,nums,0,sum);

}