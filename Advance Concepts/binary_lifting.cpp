class TreeAncestor {
public:
 vector<vector<int>>up;//table to calculate ancestors, N x log(N)
    //up array is defined as up[i][j] --> 2^j th ancestor of ith node
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        LOG = ceil(log2(n));
        up.resize(n,vector<int>(LOG+1,-1));
        for(int i=0;i<n;i++)
        {
            up[i][0]=parent[i];//2^0, i.e first ancestor of a node is its parent
        }   

        for(int j=1;j<LOG;j++)
        {
            for(int i=0;i<n;i++)
            {
                if(up[i][j-1]!=-1)
                up[i][j] = up[up[i][j-1]][j-1];
                else 
                up[i][j]=-1;
                
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        //now we need to process queries as powers of 2, 
        //lets say 5th ancestor --> binary of 5 = 101, in the table we have answers of 2^i th ancestors
        //so 5 can be rewritten as 2^2 + 2^0, so we calculate ans according to set bit

        if(k==1)
        return up[node][0];

       
        int ans=node;
        for(int j=0;j<=LOG;j++) //O(log(N))
        {
            if(k&(1<<j))
            {
                ans=up[ans][j];
                if(ans==-1)
                break;

                k-=(1<<j);
            }
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */