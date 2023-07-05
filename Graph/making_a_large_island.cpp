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
  vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n*m);

        //-----------------------making the DSU---------------
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int node = i * m + j;
                    for(int k=0;k<4;k++)
                    {
                        int row = i + dx[k];
                        int col = j + dy[k];
                        if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1)
                        {
                            int adjNode = row * m + col;
                            if(dsu.findParent(adjNode)!=dsu.findParent(node))
                            {
                                dsu.unionBySize(node,adjNode);
                            }
                        }
                    }
                }
            }
        }

        //--------------trying for every 0 in the grid-------------------------
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)continue;

                set<int>neighbours;

                for(int k=0;k<4;k++)
                {
                    int row = i + dx[k];
                    int col = j + dy[k];

                    if(row>=0&&col>=0&&row<n&&col<m&&grid[row][col]==1)
                    {
                        int adjNode = row*m+col;
                        neighbours.insert(dsu.findParent(adjNode));
                    }
                }
                int totalsize=0;
                for(auto it:neighbours)
                {
                    totalsize+=dsu.size[it];
                }
                ans = max(ans,totalsize+1);//adding the node 0 converted to one



            }
        }
        return ans==INT_MIN?n*m:ans;
    }
};