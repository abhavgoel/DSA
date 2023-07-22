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
// void inorder(TreeNode* root,vector<int>&v)
// {
//     if(root==NULL)
//     return ;

//     inorder(root->left,v);
//     v.push_back(root->val);
//     inorder(root->right,v);
// }
int ans;
void inorder(TreeNode* root,int &cnt,int k)
{
    if(root==NULL)
    return ;

    inorder(root->left,cnt,k);
    cnt++;
    if(cnt==k)
    {
        ans=root->val;
        return;
    }
    inorder(root->right,cnt,k);
}
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>v;
        int cnt=0;
        inorder(root,cnt,k);
        return ans;
    }
};