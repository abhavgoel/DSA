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
int maxi=-1;

//-------------O(n^2)----------------------------
// int height(TreeNode *root)
// {
//     if (root==NULL)
//     return 0;
//     return max(height(root->left),height(root->right))+1;
// }
// void maxDiameter(TreeNode* root)
// {
//     if(root==NULL)
//     return ;

//     int lh = height(root->left);
//     int rh = height(root->right);

//     // int maxi = -1;
//     maxi = max(maxi,lh+rh);

//     maxDiameter(root->left);
//     maxDiameter(root->right);

// }

//------------O(n)-------------------------

int maxDia(TreeNode* root,int &diameter)
{
    if(root==NULL)
    return 0;


    int lh = maxDia(root->left,diameter);
    int rh = maxDia(root->right,diameter);

    diameter = max(diameter,lh+rh);

    return 1+max(lh,rh);
}

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        maxDia(root,diameter);
        return diameter;
    }
};