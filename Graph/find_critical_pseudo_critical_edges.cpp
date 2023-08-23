class DSU{
    public:
    vector<int>rank,size,parent;

    DSU(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

    int findPar(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ult_u = findPar(u);
        int ult_v = findPar(v);

        if(ult_u==ult_v)
        return;

        if(size[ult_v] < size[ult_u])
        {
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
        else
        {
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        }
    }
};

class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}
int kruskal(int n,vector<vector<int>>&edges,int skipEdge,int addEdge)
{
    int minSum=0;
    DSU dsu(n);

    if(addEdge!=-1)
    {
        minSum+=edges[addEdge][2];
        dsu.unionBySize(edges[addEdge][0],edges[addEdge][1]);
    }

        for(int i=0;i<edges.size();i++)
        {
            if(i==skipEdge)continue;

            int wt = edges[i][2];
            int u = edges[i][0];
            int v = edges[i][1];

            if(dsu.findPar(u)!=dsu.findPar(v))
            {
                minSum+=wt;
                dsu.unionBySize(u,v);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dsu.findPar(0)!=dsu.findPar(i))
            return INT_MAX;
        }
        return minSum;
    
}

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // sort(begin(edges),end(edges),cmp);
        // DSU dsu(n);
        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }
              sort(begin(edges),end(edges),cmp);
        int minSum=kruskal(n,edges,-1,-1);
        cout<<minSum;
        vector<int>critical,pseudo;

        
        for(int i=0;i<edges.size();i++)
        {
            if(minSum < kruskal(n,edges,i,-1))
            {
                critical.push_back(edges[i][3]);//critical edge
            }
            else if(minSum == kruskal(n,edges,-1,i))
            {
                pseudo.push_back(edges[i][3]);
            }
        }
        
        return {critical,pseudo};
    }
};