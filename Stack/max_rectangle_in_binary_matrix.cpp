#include<bits/stdc++.h>
using namespace std;

int MAH(vector<int> arr)
{
    int n=arr.size();
    vector<int> left(n);
    vector<int> right(n);

    stack<pair<int,int>>s;

    //nearest smaller left

    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
        left[i]=-1;//pseudo index -1 for calculation of difference

        else if(s.size()>0 && s.top().first<arr[i])
        left[i]=(s.top().second);

        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            s.pop();

            if(s.size()==0)
            left[i]=-1;

            else left[i]=(s.top().second);
        }
        s.push({arr[i],i});
    }
    while(s.empty()==false)
    s.pop();
   
    //nearest smaller right
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
        right[i]=n;

        else if(s.size()>0 && s.top().first<arr[i])
        right[i]=(s.top().second);

        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            s.pop();

            if(s.size()==0)
            right[i]=n;

            else right[i]=s.top().second;
        }
        s.push({arr[i],i});
    }
    //reverse(right.begin(),right.end());//using indexing method for vector so no reverse
   


    vector<int> width(n);
    for(int i=0;i<right.size();i++)
    {
        int x=right[i]-left[i]-1;
        width[i]=x;
    }
    vector<int>area(n);

    for(int i=0;i<n;i++)
    {
        area[i]=arr[i]*width[i];
    }

    return *max_element(area.begin(),area.end());
}

int main()
{   const int n=4;
    const int m=5;
    int matrix[n][m] = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    
    vector<int>v;
    for(int j=0;j<m;j++)
    {
        v.push_back(matrix[0][j]);
    }

    int mx=MAH(v);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            v[j]=0;
            else
            v[j]+=matrix[i][j];
            
        }
        mx=max(mx,MAH(v));
    }
    cout<<mx;
    
}