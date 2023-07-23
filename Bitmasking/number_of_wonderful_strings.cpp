class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int>masks;
        int mask=0;
        long long ans=0;
        // masks[0]=1;
        for(int i=0;i<word.size();i++)
        {
            masks[mask]++;

            mask=mask ^ (1<<(word[i]-'a'));

            ans+=masks[mask];

            for(int j=0;j<10;j++)//a--j
            {
                int new_mask = mask ^ (1<<j);
                ans+=masks[new_mask];
            }
        }
        return ans;
    }
};