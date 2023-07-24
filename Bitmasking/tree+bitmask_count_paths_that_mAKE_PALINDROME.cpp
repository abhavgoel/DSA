class Solution {
public:
    void dfs(int node, int mask, unordered_map<int,int>&masks,vector<int>&node_masks,vector<vector<pair<int,int>>>&graph)
    {
        masks[mask]++;
        node_masks[node] = mask;

        for(auto i:graph[node])
        {
            int adjNode = i.first;
            int new_mask = mask ^ (1<<(i.second));
            //xor so that if the char is even, it will eventually be 0 in mask, 
            //and if the char occurance is odd , the bit will be set to one

            dfs(adjNode,new_mask,masks,node_masks,graph);
        }
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<pair<int,int>>>graph(n);
        //any string with all even occurances of a number or an odd 
        //occurance of a character can be rearranged to be a palindrome
        for(int i=1;i<n;i++)
        {
            int u = parent[i];
            int v = i ; 
            graph[u].push_back({v,s[i]-'a'});
            
        }

        unordered_map<int,int>masks;//map to store mask values and their frequency

        vector<int>node_masks(n);//vector to store all masks value 
        //so that we can interate over them

        //the idea is to create bitmasks for every node and store their frequencies
        //the mask with value 0 or only 1 bit set can be palindromes

        //so we start dfs from the root node and store masks 
        //frequency of every node in the map, and the mask value of that node

        dfs(0,0,masks,node_masks,graph);

        // for(auto i:node_masks)
        // cout<<i<<" ";

        long long ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                int msk = node_masks[i] ^ (1<<j);//bit set to 1

                ans+=masks[msk];

                
            }
             ans+=masks[node_masks[i]]-1;//-1 because the char will itself be included one time
            
        }
        return ans/2;//every pair will be u,v and v,u but we need only u,v, so divide by 2
    }
};