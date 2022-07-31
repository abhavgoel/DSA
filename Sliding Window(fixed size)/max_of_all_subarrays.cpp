#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfAllSubarrays(int arr[],int n,int k)
{
    vector<int> v;
    int i=0,j=0;
    deque<int> l;

    while(j<n)
    {
        while(l.size()>0 && l.back()<arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);
        if(j-i+1<k)
        j++;
        else if(j-i+1==k)
        {
            v.push_back(l.front());
            if(l.front()==arr[i])
            {
                l.pop_front();
            }
            i++;
            j++;

        }
    }
    // cout<<v.size();
    return v;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int k;
    cin>>k;
    vector<int> v;
    v=maxOfAllSubarrays(arr,n,k);
    for(auto i:v)
        cout<<i<<" ";
    
}

