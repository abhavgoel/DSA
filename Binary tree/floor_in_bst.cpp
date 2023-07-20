int floor(Node* root, int x) {
    // Code here
    if(root==NULL)
    return -1;
    
    int floor=-1;
    while(root)
    {
        if(x==root->data)
        return root->data;
        
        else if(x>root->data)
        {
             floor=root->data;
            root=root->right;
           
        }
        else root=root->left;
    }
    return floor;
}