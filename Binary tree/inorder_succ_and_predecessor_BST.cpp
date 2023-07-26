class Solution
{
    public:
    Node* pred(Node* root,int key)
    {
        Node* predd=NULL;
        while(root!=NULL)
        {
            if(root->key >= key)
            root=root->left;
            else if(root->key < key)
            {
                predd=root;
                root=root->right;
            }
            
        }
        return predd;
    }
    Node* succ(Node* root,int key)
    {
        Node* succc=NULL;
        while(root!=NULL)
        {
            if(root->key > key)
            {
                succc=root;
                root=root->left;
            }
            else if(root->key <= key)
            {
                
                root=root->right;
            }
            
        }
        return succc;
        
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
       pre = pred(root,key);
       suc = succ(root,key);
       
       
    }
};
