class Solution {
public:
    vector<int>v;
    vector<int> preorderTraversal(TreeNode* root) {
        // if(root!=NULL)
        // {
            
        // v.push_back(root->val);
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);
        // }
        // return v;
        if(root==NULL)return {};

        stack<TreeNode*>st;
        vector<int>preorder;

        st.push(root);
        while(st.empty()==false)
        {
            TreeNode *curr = st.top();
            st.pop();

            preorder.push_back(curr->val);
            if(curr->right)
            st.push(curr->right);

            if(curr->left)
            st.push(curr->left);
        }
        return preorder;
    }
};