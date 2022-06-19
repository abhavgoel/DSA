#include<bits/stdc++.h>
using namespace std;
void lRotateOne(int a[],int n)
{
    int temp=a[0];
    for(int i=1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    a[n-1]=temp;
}