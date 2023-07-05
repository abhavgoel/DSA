class Solution {
public:
//all number repeats 3 times , find a number that comes 1 time
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            int ones=0;
            int zeros=0;
            for(auto it:nums)
            {
                if(((it>>i)&1 )==1)ones++;
                else zeros++;
            }
            if(ones%3!=0)
            {
                res = res | (1<<i);
            }
        }
        return res;
        
    }
};