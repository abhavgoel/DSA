class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;
        
        q.push({root,0});
        
        map<int,int>mp;//mp[vertical]->node
        
        while(!q.empty())
        {
            Node *node = q.front().first;
            int vertical = q.front().second;
            q.pop();
            
            // if(mp.count(vertical)==0)
            mp[vertical] = node->data;//we need last node of every vertical column
            
            
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