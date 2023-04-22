#include<bits/stdc++.h>
using namespace std;
//we take LIS from front and back and sum them to see max ans
//-1 for excluding the elment taken twice
#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& nums, int n) {
	  // Write your code here.	
	  //int n=nums.size();
        vector<int>dp1(n,1);
        
        for(int i=0;i<n;i++)
        {
            
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]>nums[prev])
                dp1[i]=max(dp1[i],1+dp1[prev]);
            }

        }   

		 vector<int>dp2(n,1);
        
        for(int i=n-1;i>=0;i--)
        {
            
            for(int prev=n-1;prev>i;prev--)
            {
                if(nums[i]>nums[prev])
                dp2[i]=max(dp2[i],1+dp2[prev]);
            }

        } 
		int maxi=-1;
		for(int i=0;i<n;i++)
		{
			maxi=max(maxi,dp1[i]+dp2[i]-1);
		}
		return maxi;
} 
