class Solution {
public:
    vector<int>topoSort(vector<vector<int>>&graph,vector<int>&indegree){
        queue<int>q;
        vector<int>res;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();
            
            res.push_back(it);

            for(auto j:graph[it])
            {
                indegree[j]--;
                if(indegree[j]==0)
                {
                    q.push(j);
                }
            }

        }
        return res.size()==indegree.size()?res:vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        

        for(int i=0;i<group.size();i++)
        {
            if(group[i]==-1)
            group[i]=m++; //new group to those who dont have a group
        }

        vector<vector<int>>groupGraph(m);
        vector<vector<int>>beforeGraph(n);
        vector<int>beforeDeg(n);
        vector<int>groupDeg(m);
        //topological of item and topological order of groups
        //then segregate items in same group according to respective order
        for(int i=0;i<n;i++)
        {
            for(auto prev:beforeItems[i])
            {
                beforeGraph[prev].push_back(i); //prev --> i
                beforeDeg[i]++;

                if(group[i]!=group[prev])
                {
                    groupGraph[group[prev]].push_back(group[i]); // group[prev] comes before group[i]
                    groupDeg[group[i]]++;
                }
            }
        }

        vector<int>itemTopo = topoSort(beforeGraph,beforeDeg);
        vector<int>groupTopo = topoSort(groupGraph , groupDeg);

        // for(auto i:itemTopo)
        // cout<<i<<" ";
        
        // cout<<endl;

        // for(auto i:groupTopo)
        // cout<<i<<" ";
        
        vector<vector<int>>groupToItems(m);

        for(int i=0;i<itemTopo.size();i++)
        {
            groupToItems[group[itemTopo[i]]].push_back(itemTopo[i]);//sorting 
            //elements in group according to topological order
        }

        vector<int>ans;
        for(int i=0;i<groupTopo.size();i++)
        {
            for(auto j:groupToItems[groupTopo[i]])
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};