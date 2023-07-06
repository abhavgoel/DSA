class DSU
{
    public:
    vector<int>rank,parent,size;
    
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);
        //connecting the components having same row or col
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;

                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    if(dsu.findParent(i)!=dsu.findParent(j))
                    dsu.unionBySize(i,j);
                }
            }
        }
        //in a component ,number of elemnts in it -1 can be deleted for maximum ans, coz we can delete the last remaining element as it woont have same row or col
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dsu.parent[i]==i)
            ans=ans+(dsu.size[i]-1);

        }
        return ans;

    }
};