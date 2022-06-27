#include<bits/stdc++.h>
using namespace std;
//only for positive numbers
int largest__subarray(int arr[],int n,int k)//k=given sum
{
    int sum=0;
    int mx=INT_MIN;
    int i=0;int j=0;
    while(j<n)
    {
        sum=sum+arr[j];

        if(sum<k)
        j++;

        else if(sum==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(sum>k)
        {
            while(sum>k)
            {
                sum=sum-arr[i];
                i++;
            }
            j++;
        }

        
    }
    return mx;
}
int main()
{
	int arr[15]={4, 1, 1, 1, 2, 3, 5};
	int k = 5;
    int n=7;
	cout << largest__subarray(arr,n, k);
	return 0;
}