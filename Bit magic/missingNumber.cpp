/* given array of n number .Find the missing number in the array that has values of range 1 to n+1
every number appears exactly once.
Here one number is missing . Find it  */
//example n=3
//values = 1 --> 4
//array = 1,4,3
//output =2
/* idea is that we take XOR of all n+1 elements with array
(1^2^3....^(n+1))^(arr[0]^arr[1].....arr[n-1])*/
int missingNumber(int arr1[],int arr2[],int n)
{
    int res1=0,res2=0,miss;
    for(int i=0;i<n;i++)
    {
        res1=res1^arr1[i];//arr1 is natural number array
    }
    for(int i=0;i<n;i++)
    {
        res2=res2^arr2[i];//arr2 with missing number
    }
    miss=res1^res2;
    return miss;
}