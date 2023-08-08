class Solution {
public:
 //using bitmask
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        int subset_count = (1<<n);//TOTAL SUBETS = 2^N

        //for eg = if n =3
        /*
        1. 0 0 0
        2. 0 0 1
        3. 0 1 0
        4. 1 0 0
        5. 0 1 1
        6. 1 0 1
        7. 1 1 0
        8. 1 1 1

        masks of subsets would be like this
        so we can iterate till 2^n and find which bits are set and then pushback the subset to the ans
        */
        vector<vector<int>>ans;
        for(int mask=0;mask<subset_count;mask++)
        {
            vector<int>subset;

            for(int i=0;i<n;i++)
            {
                if(mask & (1<<i))
                subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};