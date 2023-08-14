#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& a, int k){
    map<long long ,int>mp;
    long long sum=0;
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        sum+=a[i];

        if(sum==k)
        {
            ans=max(ans,i+1);
        }

        long long rem = sum-k;
        if(mp.find(rem)!=mp.end())
        {
            int len = i-mp[rem];
            ans=max(ans,len);
        }

        if(mp.find(sum)==mp.end())
        mp[sum]=i;

    }
    return ans;
}