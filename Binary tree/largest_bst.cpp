class NodeValue
{
    public:
    int maxNode;
    int minNode;
    int maxSize;
    
    NodeValue(int minNode,int maxNode,int maxSize)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue helper(Node* root)
    {
        if(root==NULL)
        return NodeValue(INT_MAX,INT_MIN,0);//leaf node so sending max values so, that in next step the leaf node takes the value of itself 
        
        //doing a postorder traversal ,bcoz to check for bst, we need ;left tree computations and right tree computations before hand
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        //if current node is greater than max node of left subtree and smaller than smallest node of right subtree
        //then its a BST
        if(left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(min(left.minNode , root->data) , max(root->data, right.maxNode),left.maxSize+right.maxSize+1);
            
        }
        return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));//else return max values bcoz that subtree would never be a BST
        
    }
    
    int largestBst(Node *root)
    {
    	NodeValue obj = helper(root);
    	return obj.maxSize;
    }
};