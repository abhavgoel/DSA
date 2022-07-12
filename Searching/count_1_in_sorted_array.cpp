    #include<bits/stdc++.h>
    using namespace std;
    int countOnes(int arr[], int N)
    {
        
        // Your code here
        int low=0;
        int high=N-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(arr[mid]==0)
            high=mid-1;
            else
            {
                if(mid==N-1 || arr[mid+1]!=arr[mid])
                return mid+1;
                else low=mid+1;
            }
            
        }
        return 0;
        
    }