#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
    node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
int height(node *root)
{
    if (root==NULL)
    return 0;
    return max(height(root->left),height(root->right))+1;
}

// int maxDepth(TreeNode* root) {
//          if(root==NULL)
//             return NULL;
        
        
//         int left = maxDepth(root->left);
//         int right = maxDepth(root->right);
        
//         int ans = max(left,right)+1;
        
//         return ans;
//     }