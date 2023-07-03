#include<bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int>rank,parent,size;
    public:
    DSU(int n)
    {
        rank.resize(n+1,0);//n+1 , so it works for both 0 based and 1 based indexing
        size.resize(n+1,1);//every nide has size 1
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findParent(int node)
    {
        if(node==parent[node])//node itself is the ultimate parent
        return node;

        return parent[node] = findParent(parent[node]);//recursively finding the ultimate parent
    }
    void unionByRank(int u,int v)
    {
        int ultParent_u = findParent(u);
        int ultParent_v = findParent(v);

        if(ultParent_u==ultParent_v)return;

        else if(rank[ultParent_u]<rank[ultParent_v])//rank of u is less, 
        {
            parent[ultParent_u]=ultParent_v;//attach u to v, parent of u is now v
        }
        else if(rank[ultParent_v]<rank[ultParent_u])//rank of v is less,
        {
            parent[ultParent_v]=ultParent_u;// attach v to u, parent of v is now u
        }
        else //both have same ranks, so attatch anyone to other
        {
            parent[ultParent_v]=ultParent_u;//attaching v to u, that means 2nd node to 1st node
            rank[ultParent_u]++;
        }

    }
    void unionBySize(int u,int v)
    {
        int ultParent_u = findParent(u);
        int ultParent_v = findParent(v);

        if(ultParent_u==ultParent_v)return;

        else if(size[ultParent_u]<size[ultParent_v])
        {
            parent[ultParent_u]=ultParent_v;
            size[ultParent_v]+=size[ultParent_u];
        }
        else if(size[ultParent_v]<size[ultParent_u])
        {
            parent[ultParent_v]=ultParent_u;
            size[ultParent_u]+=size[ultParent_v];
        }
        else 
        {
            parent[ultParent_v]=ultParent_u;
            size[ultParent_u]+=size[ultParent_v];
        }
    }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int>mp;//mapping emails to a node

        //["John","johnsmith@mail.com","john_newyork@mail.com"]
        //    0              1                  2
        //["John","johnsmith@mail.com","john00@mail.com"]
        //.   1.           1                    2

        //["Mary","mary@mail.com"]
        //.  2.          1


        DSU dsu(accounts.size());

        //----------------------creating the Disjoint sets-------------------
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)//starting from 1 to skip the name
            {
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end())//doesnot contains this mail
                mp[mail]=i;//assinging node to the mail
                else//we have to merge them to one
                dsu.unionByRank(mp[mail],i);

            }
        }
        //-----------------------------------------------------------------------
        vector<vector<string>>mergedMails(accounts.size());//max size can be 'n'
        for(auto i:mp)
        {
            string mail = i.first;
            int node = dsu.findParent(i.second);

            mergedMails[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<mergedMails.size();i++)
        {
            if(mergedMails[i].size()==0)
            {
                //mergedMails.erase(mergedMails.begin()+i-1);
                continue;
            }
            sort(mergedMails[i].begin(),mergedMails[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto i:mergedMails[i])
            {
                temp.push_back(i);
            }
            ans.push_back(temp);

        }

        return ans;
   }
};