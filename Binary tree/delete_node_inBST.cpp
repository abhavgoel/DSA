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
class Solution {
public:
TreeNode* findRightMost(TreeNode* root)
{
    if(root->right==NULL)
    return root;

    return findRightMost(root->right);
    
}
TreeNode* helper(TreeNode* root)
{
    if(root->right==NULL)
    return root->left;
    if(root->left==NULL)
    return root->right;

    TreeNode* rightmost = findRightMost(root->left);//we have to connect rightmost node of left subtree to first node of right subtree to maintain BST
    rightmost->right = root->right;

    return root->left;
}
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root==NULL)
        return NULL;
        if(root->val==val)
        return helper(root);


        TreeNode* curr = root;

        while(curr!=NULL)
        {
            if(curr->val > val)
            {
                if(curr->left!=nullptr && curr->left->val == val)
                {
                    curr->left = helper(curr->left);
                    break;
                }
                else curr = curr->left;
            }

            else if(curr->val < val)
            {
                if(curr->right!=nullptr && curr->right->val==val)
                {
                    curr->right = helper(curr->right);
                    break;
                }
                else curr=curr->right;
            }
            
        }
        return root;
    }
};