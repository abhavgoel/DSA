class Solution {
public:
    bool isLeaf(Node *root)
    {
        if(root->right==NULL&&root->left==NULL)
        return true;
        else return false;
        
    }
    void addleft(Node *root,vector<int>&ans)
    {
        Node *node = root;
        node = node->left;
        
        while(node!=NULL)
        {
            if(isLeaf(node)==false)
            {
                ans.push_back(node->data);
            }
            
            if(node->left)node=node->left;
            else node=node->right;
        }
    }
    void addleaves(Node *root,vector<int>&ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left)addleaves(root->left,ans);
        if(root->right)addleaves(root->right,ans);
        
    }
    void addright(Node* root , vector<int>&ans)
    {
        
        Node *node = root;
        node=node->right;
        stack<int>st;
        while(node!=NULL)
        {
            if(!isLeaf(node))st.push(node->data);
            
            if(node->right)node=node->right;
            else node=node->left;
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    }


    vector <int> boundary(Node *root)
    {
        if(root==NULL)
        return {};
        
        vector<int>ans;
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return ans;
        }
        
        
        //first we add the left part of the tree
        //then the leaf nodes
        //then we add the right part of the tree in reverse order, we'll use stack for it
        ans.push_back(root->data);
        addleft(root,ans);
        addleaves(root,ans);
        addright(root,ans);
        return ans;
    }
};