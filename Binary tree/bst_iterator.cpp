/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//approach -1 Brute force - store the inorder in a vector then use it for the fucntions,
//but space complexity will be O(N)

//approach -2
//O(H) time
class BSTIterator {
public:
stack<TreeNode*>st;
void pushAll(TreeNode* node)
{
    for(TreeNode* i =node;i!=NULL;i=i->left)
    st.push(i);
}
    BSTIterator(TreeNode* root) {
      pushAll(root);  
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(st.empty()==false)
        return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */