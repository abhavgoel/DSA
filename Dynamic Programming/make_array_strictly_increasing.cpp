#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

// 1 5      3 6 7
//   ^      ^
//   prev   i

//we can either replace the current index from just greater element from previous or if the next element is greater than prev element, we can skip and check for further indexes
int helper(int i,int prev,vector<int>&arr1,vector<int>&arr2,  map<pair<int,int>,int>&mp)
{
    if(i>=arr1.size())
    return 0;
    
    if(mp.find({i,prev})!=mp.end())
    return mp[{i,prev}];

    int opt1 = 1e9;

    if(arr1[i]>prev)
    opt1 = helper(i+1,arr1[i],arr1,arr2,mp);

    int idx = upper_bound(begin(arr2),end(arr2),prev) - arr2.begin();
    //---->finding an element just greater than prev, to try for another option

    int opt2=1e9;
    if(idx!=arr2.size())
    {
        //arr1[i]=arr2[idx]
        opt2 = 1 + helper(i+1,arr2[idx],arr1,arr2,mp);
    }
    return mp[{i,prev}] = min(opt1,opt2);
}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        map<pair<int,int>,int>mp;
        int ans = helper(0,INT_MIN,arr1,arr2,mp);
        return ans==1e9?-1:ans;
        
    }
};