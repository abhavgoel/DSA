#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getSum(long long count,long long mid)
    {
        return (mid*count) - (count*(count+1))/2;
    }
    int maxValue(int n, int index, int maxSum) {
        long long start = 1;
        long long end = maxSum;
        int res=0;
        while(start<=end)
        {
            long long mid = start + (end-start)/2;
            long long leftsum = getSum(min((long long)index,mid-1),mid);//determiniing of how much elements on left are to be counted in sum
            long long rightsum = getSum(min((long long)(n-index-1),mid-1),mid);

            leftsum=leftsum + max((long long)index-(mid-1),0LL);//adding '1's  
            rightsum = rightsum + max((long long)(n-index-1)-(mid-1),0LL);

            if(leftsum+rightsum+mid<=maxSum)
            {
                res=mid;
                start=mid+1;
            }
            else end=mid-1;

        }
        return res;

    }
};