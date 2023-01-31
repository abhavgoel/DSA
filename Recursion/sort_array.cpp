#include<bits/stdc++.h>
using namespace std;

void sortt(vector<int>&v)
{
    if(v.size()==1)
    return ;

    int last=v[v.size()-1];
    v.pop_back();
    sortt(v);
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>last)
        {
            swap(v[i],last);  
        }
    }
    v.push_back(last);

}
//2nd solution
void insert(vector<int>&v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v[v.size()-1];
    v.pop_back();
    insert(v,temp);
    v.push_back(val);

}
void sort2(vector<int>&v)
{
    if(v.size()==1)
    return;

    int temp=v[v.size()-1];
    v.pop_back();
    sort2(v);
    insert(v,temp);

}
int main()
{
    vector<int> v = {10,9,8,7,6,5,4,3,2,1};
    sortt(v);

    for(auto i:v)
    cout<<i<<" ";
}