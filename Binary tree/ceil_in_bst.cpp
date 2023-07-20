int ceilBST(TreeNode* root,int key)
{
    int ceil=-1;

    while(root)
    {
        if(root->val==key)
        return root->val;

        if(key>root->val)
        {
            root=root->right;
        }
        if(key<root->val)
        {
            ceil=root->val;
            root=root->left;
        }
    }
}