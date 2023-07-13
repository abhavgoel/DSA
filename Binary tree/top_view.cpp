class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //we need to find the first node of every vertical line in every level
        //lets map it like this - mp[vertical]-->node
        
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        map<int,int>mp;//mp[vertical]->node , using map bcoz we only need 1 node of one vertical line
        
        while(!q.empty())
        {
            Node *node = q.front().first;
            int vertical = q.front().second;
            q.pop();
            
            if(mp.count(vertical)==0)
            mp[vertical] = node->data;
            
            if(node->left)
            q.push({node->left,vertical-1});
            if(node->right)
            q.push({node->right,vertical+1});
        }
        
        vector<int>ans;
        
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

};
