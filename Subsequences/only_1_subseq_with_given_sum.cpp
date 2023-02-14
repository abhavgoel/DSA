#include<bits/stdc++.h>
using namespace std;


bool oneSubseq(int index,vector<int>&ds,vector<int>&nums,int s,int sum)
{
    if(index==nums.size())
    {
        if(s==sum)
        {
        for(auto i:ds)cout<<i<<" ";
        cout<<endl;
        return true;
        }
         return false;
    }

    ds.push_back(nums[index]);
    s=s+nums[index];
    if(oneSubseq(index+1,ds,nums,s,sum)==true)
    return true;

    s=s-nums[index];
    ds.pop_back();
    if(oneSubseq(index+1,ds,nums,s,sum)==true)
    return true;

    return false;


   
}



int main()
{
    vector<int>nums={1,2,1};
    vector<int>ds;
    int sum =2 ;
    oneSubseq(0,ds,nums,0,sum);

}