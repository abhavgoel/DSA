class Solution {
public:
int numtickets;
bool dfs(string node ,vector<string>&path, unordered_map<string,vector<string>>&graph)
{
    path.push_back(node);
    if(path.size()==numtickets+1)
    {
        return 1;
    }

    for(auto it=graph[node].begin();it!=graph[node].end();it++)
    {
        string to = *it;
        graph[node].erase(it);

        if(dfs(to,path,graph))
        return true;

        graph[node].insert(it,to);

    }
    path.pop_back();
    return 0;
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        numtickets=n;

        unordered_map<string,vector<string>>graph;

        for(int i=0;i<n;i++)
        {
            string u = tickets[i][0];
            string v = tickets[i][1];

            graph[u].push_back(v);
        }
        
        for(auto &i:graph)
        {
            sort(begin(i.second),end(i.second));
            // cout<<i.first<<"-->";
            // for(auto it:i.second)
            // cout<<it<<" ";
            // cout<<endl;

        }

        vector<string>path;

        dfs("JFK",path,graph);
        return path;


    }
};