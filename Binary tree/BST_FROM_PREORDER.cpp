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
// int preindex= 0;
// unordered_map<int,int>mp;
// TreeNode *helper(vector<int>&inorder,vector<int>&preorder,int instart,int inend)
// {

//     if(instart>inend)
//     return nullptr;

//     TreeNode* root = new TreeNode(preorder[preindex++]);

//     int index = mp[root->val];

//     root->left = helper(inorder,preorder,instart,index-1);
//     root->right = helper(inorder,preorder,index+1,inend);

//     return root;
// }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         vector<int>inorder=preorder;
//         sort(inorder.begin(),inorder.end());
//         int n = inorder.size();
//         for(int i=0;i<inorder.size();i++)
//         {
//             mp[inorder[i]]=i;
//         }
//         //now we can create a tree from bin tree and preorder, bcoz the inorder ofm BST is always sorted
//         return helper(inorder,preorder,0,n-1);

//     }

    TreeNode* helper(int &i,int bound,vector<int>&preorder)//we pass i by reference bcoz we need it to be updated after we have inserted the elements
    //to left of tree, and we have to begin from the last updated i to add right elements
    {
        if(i==preorder.size() || preorder[i] > bound)return NULL;

        TreeNode* root = new TreeNode(preorder[i++]); 
        root->left = helper(i,root->val,preorder);
        root->right = helper(i,bound,preorder);

        return root;
    }
 TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i=0;
    return helper(i,INT_MAX,preorder);
 }
};