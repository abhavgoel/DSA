class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        //need to check if all nodes visited that is all bits set to 1 - bitmask intuition
        queue<pair<pair<int,int>,int>>q;
        set<pair<int,int>>st;
        //to exculde revisiting same nodes we store {node,mask} ie the state of traversal, in set
        //so if we go from 0-->1-->0-->1 , the 2nd 0-->1 will be excluded as it would have same {node,mask} value

        for(int i=0;i<n;i++)
        {
            int mask = 1<<i;

            q.push({{i,mask},0});
            st.insert({i,mask});
        }
        int allVis = (1<<n)-1;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();


            int currNode = it.first.first;
            int currMask = it.first.second;
            int currDis = it.second;

            if(currMask==allVis)
            return currDis;

            for(auto i:graph[currNode])
            {
                int newMask = currMask | (1<<i);
                if(st.find({i,newMask})==st.end())
                {
                    st.insert({i,newMask});
                    q.push({{i,newMask},currDis+1});
                }
            }

        }
        return -1;

    }
};