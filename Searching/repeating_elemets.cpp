#include<bits/stdc++.h>
using namespace std;

int repeating(int arr[],int n)
{
    bool visited[n]={false};

    for(int i=0;i<n;i++)
    {
        if(visited[arr[i]])
        return arr[i];

        visited[arr[i]]=true;
    }
}

// O(n) and O(n) time and space