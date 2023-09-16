#define P pair<int,pair<int,int>>
class Solution {
public:
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<P,vector<P>,greater<P>>pq;

        pq.push({0,{0,0}});//{effort,{i,j}}

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int i = it.second.first;
            int j = it.second.second;
            int prevEffort = it.first;

            if(i==n-1 && j==m-1)
            return prevEffort;

            for(int k=0;k<4;k++)
            {
                int row = i + dx[k];
                int col = j + dy[k];
                
                

                if(row>=0 && row<n && col>=0 && col<m)
                {
                    int effort = max(prevEffort,abs(heights[i][j] - heights[row][col]));
                    //taking max from prev effort of the path
                    if(effort<dist[row][col])
                    {
                        dist[row][col]=effort;
                        pq.push({dist[row][col],{row,col}});
                    }
                }
            }

        }
        return -1;

    }
};