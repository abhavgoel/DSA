//tells if 2 nodes present in one component of a graph in CONSTANT time
//used for dynamic graphs

//disjoint sets are the sets which have nothing in common
//so by using Union operation we are merging two disjoint sets, thats the the data structure is called Disjoint Set Union

//method
// 1 . find ultimates parents
// 2 . Find the ranks of ultimate parents
// 4 . connect smaller rank to larger rank always

// the reason for this is when finding parent we recursively go from each node to the previous
//so when we connect smaller to larger rank , we are eventually keeping the overall branch of the tree small

//to find ultimate parent we use Path compression

//RANK = upper bound of height of the tree , used to calculate the size difference when merging


#include<bits/stdc++.h>
using namespace std;

class DSU{
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

int main()
{
    DSU dsu(7);
    dsu.unionBySize(1,2);//means we are connecting 1 to 2
    dsu.unionBySize(2,3);
    dsu.unionBySize(4,5);
    dsu.unionBySize(6,7);
    dsu.unionBySize(5,6);
    if(dsu.findParent(3)==dsu.findParent(7))
    cout<<"Same set"<<endl;

    else if(dsu.findParent(3)!=dsu.findParent(7))
    cout<<"not same set"<<endl;

    dsu.unionBySize(3,7);//connecting 3 and 7;

    if(dsu.findParent(3)==dsu.findParent(7))
    cout<<"Same set"<<endl;

    else if(dsu.findParent(3)!=dsu.findParent(7))
    cout<<"not same set"<<endl;
    
}