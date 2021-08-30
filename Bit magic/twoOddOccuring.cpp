#include<bits/stdc++.h>
using namespace std;
void oddAppearing(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int count =0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;

        }
        if(count%2!=0)
        cout<<arr[i]<<endl;
    }
}
void oddAppearing1(int arr1[],int n)
{
    int XOR =0,res1=0,res2=0;
    for(int i=0;i<n;i++)
    {
        XOR=XOR^arr1[i];
    }
    int sn=XOR&~(XOR-1);//right most bit set
    for(int i=0;i<n;i++)
    {
        if((arr1[i]&sn)!=0)
        res1=res1^arr1[i];
        else
        res2=res2^arr1[i];
    }
    cout<<res1<<res2;
}
/* idea is we find the right most bit by the XOR expression because if that
bit is set then the corrsponding bits of the two odd occuring elements would be different
so we take the rightmost bit set number and take XOR of it with full array
and it would separate out the number with that bit set and the number with that bit not set*/
