#include<bits/stdc++.h>
using namespace std;
//O(n^2)
int maxCircularSubarray(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr_max=arr[0];
        int curr_sum=arr[0];

        for(int j=1;j<n;j++)
        {
            int index = (i+j)%n;
            curr_sum=curr_sum+arr[i];
            curr_max=max(curr_max,curr_sum);

        }
        res=max(res,curr_max);
    }
    return res;
}

//efficient 
//min subarray sum using kadane's algo therm subtracting from total subarray sum
int normalMaxSum(int arr[],int n)
{
    int res=arr[0];
   int  maxEnding=arr[0];
    for(int i=1;i<n;i++)
    {
        maxEnding=max(arr[i],maxEnding+arr[i]);
        res=max(res,maxEnding);
    }
    return res;
}
int overallMaxSum(int arr[],int n)
{
    int maxNormal=normalMaxSum(arr,n);
    if(maxNormal<0)
    return maxNormal;
    

    int arr_sum=0;
 
    for(int i=0;i<n;i++)
    {
        arr_sum=arr_sum+arr[i];
        arr[i]=-arr[i];
        
    }
    int max_circular=arr_sum + normalMaxSum(arr,n);
    return max(maxNormal,max_circular);
}