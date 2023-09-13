class Solution {
public:

//moore's voting algorithm  
//calculating the affect of an element ina  part of array
//if an element occurs x times and other occurs x times , then it would not be a majority element
//at the last if the effect of a number is not cancelled we need to perform an extra check that if that 
//element is really a majority element or not
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int ele=INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count++;
                ele = nums[i];
            }
            else if(nums[i] == ele)
            {
                count++;
            }
            else count--;
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
            {
                count++;
            }
        }
        if(count>n/3)
        return ele;
        else return -1;
    }
};