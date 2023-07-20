#include<bits/stdc++.h>
using namespace std;

TreeNode* searchBST(TreeNode* root,int target)
{
    while(root!=NULL && root->val!=target)
    {
        root= val<root->val?root->left:root->right;
    }
    return root;
}