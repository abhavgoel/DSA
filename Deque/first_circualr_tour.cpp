#include<bits/stdc++.h>
using namespace std;

//Consider an arrangement where n petrol pumps are arranged in a circular manner.
// We need to find the first petrol pump from where we can visit all petrol pumps and 
//come back to the petrol pump without ever going out of the petrol.

int firstPetrolPump(int petrol[], int dist[],int n)
{
    for(int start=0;start<n;start++)
    {
        int curr_petrol=0;
        int end=start;
        while(true)
        {
            curr_petrol=curr_petrol + (petrol[end]-dist[end]);
            if(curr_petrol<0)
            break;

            end=(end+1)%n;
            if(end==start)
            return (start+1);//position
        }

    }
}
//O(n^2)

//efficient solution using queue


//approach  -  while petrol greater than equal to 0 enque the stations, and deque from front
//if petrol <0

int firstPeterolpump(int gas[],int cost[],int n)
{
    int curr_petrol =0;
        
        int start=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            curr_petrol= curr_petrol + (gas[i]-cost[i]);
            
            if(curr_petrol <0)
            {
                start = i+1;
                prev=prev+curr_petrol;
                curr_petrol=0;
            }
        }
        if(curr_petrol+prev>=0)
            return start;
        else return -1;

}