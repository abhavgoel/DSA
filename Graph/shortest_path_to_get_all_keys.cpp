class Solution {
public:
    //we have to store a third state in the visited array, so that it can store the key number,
    //and further when we encouter a lock it can be checked that if we have the key we need for that lock
    //we can use bitmask for it
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};

    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int startx;int starty;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='@')
                {
                    startx = i;
                    starty = j;
                    break;
                }
                
            }
        }
        int keys = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>='a' && grid[i][j]<='f')//collecting keys
                keys++;
            }
        }
        int finalmask = pow(2,keys)-1;
        //order is same so mask would be filled like this--> 001 for 'a' key , 011 for both 'b' and 'a' keys and so on;
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(finalmask+1,0)));
        //vis[i][j][mask]
        queue<vector<int>>q;
        q.push({startx,starty,0,0});//{i,j,steps,mask};

        while(q.empty()==false)
        {
            auto it = q.front();
            q.pop();

            int i = it[0];
            int j = it[1];
            int steps = it[2];
            int mask = it[3];
            cout<<steps<<" "<<endl;
            if(mask==finalmask)//collected all keys
            return steps;

            for(int k=0;k<4;k++)
            {
                int row = i + dx[k];
                int col = j + dy[k];

                if(row>=0 && col>=0 && row<n && col<m && grid[row][col]!='#')
                {
                    //now we have 3 cases
                    //case -1 -->if there is a lock
                    //case - 2 --> if there is a key
                    //case -3 --> if there is a '.'

                    if((grid[row][col]=='.' || grid[row][col]=='@') && vis[row][col][mask]==0)
                    {
                        vis[row][col][mask]=1;
                        q.push({row,col,steps+1,mask});
                        //cout<<row<<" "<<col<<endl;
                    }
                    else if(grid[row][col]>='a' && grid[row][col]<='f' 
                    &&vis[row][col][mask]==0)//key
                    {
                        int newmask = mask | (1<<(grid[row][col]-'a'));
                        if(vis[row][col][newmask]==0)
                        {
                            vis[row][col][newmask]=1;
                            q.push({row,col,steps+1,newmask});
                            //cout<<row<<" "<<col<<endl;
                        }
                    }
                    else if(grid[row][col]>='A' && grid[row][col]<='F' 
                    && vis[row][col][mask]==0)//lock
                    {
                        if(((mask >> (grid[row][col]-'A'))&1)==1)//have the key for this lock
                        {
                            vis[row][col][mask]=1;
                            q.push({row,col,steps+1,mask});
                            //cout<<row<<" "<<col<<endl;
                        }
                    }
                }
            }
        }
        return -1;



    }
};