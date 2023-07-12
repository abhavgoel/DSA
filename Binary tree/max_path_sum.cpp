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
    int maxpath(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        return 0;

        int leftsum = max(maxpath(root->left,maxi),0);//not taking negative sum
        int rightsum = max(maxpath(root->right,maxi),0);
        maxi = max(maxi,(root->val+leftsum+rightsum));

        return root->val + max(leftsum,rightsum);

    }
    int maxPathSum(TreeNode* root) {
        int maxi= INT_MIN;
        maxpath(root,maxi);
        return maxi;
    }
};