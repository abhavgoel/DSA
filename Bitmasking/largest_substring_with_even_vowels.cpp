class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<long long,int>mp;

        int n = s.size();
        long long mask=0;
        mp[0]=-1;
        unordered_set<char>st={'a','e','i','o','u'};
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(st.find(s[i])!=st.end())
            {
                mask = mask ^ (1<<(s[i]-'a'));
                cout<<i<<" "<<mask<<endl;
                
            }
            if(mp.find(mask)==mp.end())//new mask then update index
            mp[mask]= i;

            else //mask seen before
            ans = max(ans,i-mp[mask]);
            
        }
        return ans; 
    }
};