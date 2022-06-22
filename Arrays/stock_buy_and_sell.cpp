#include<bits/stdc++.h>
using namespace std;
int maxProfit(int price[],int n)
{
    int profit=0;
    for(int i=0;i<n;i++)
    {
        if(price[i]>price[i-1])
        {
            profit = profit + (price[i]-price[i-1]);
        }
    }
    return profit;
}