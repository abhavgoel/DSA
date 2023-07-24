class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();

        int mask=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {   
            mask = mask^(1<<(s[i]-'0'));           

            for(int j=0;j<10;j++)
            {
                int new_mask = mask^(1<<j);

                if(mp.find(new_mask)!=mp.end())
                ans=max(ans,i-mp[new_mask]);
            }
            if(mp.find(mask)==mp.end())
            mp[mask] = i;
            else 
            ans = max(ans,i-mp[mask]);

        }
        return ans;
    }
};