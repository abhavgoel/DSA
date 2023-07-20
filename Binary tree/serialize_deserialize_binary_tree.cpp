/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        queue<TreeNode*>q;
        string s="";
        q.push(root);

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            if(curr==NULL)s.append("#,");
            else 
            {
                s.append(to_string(curr->val)+',');
            }
            if(curr!=NULL)//also pushing null nodes for a leaf node
            {
                q.push(curr->left);
                q.push(curr->right);
            }
            
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);//creates a string stream object
        string str;
        getline(s,str,',');//reads string stream object till first occurence of ',', and stores it int str
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();

            getline(s,str,',');

            if(str=="#")
            {
                curr->left=NULL;
            }
            else 
            {
                TreeNode* leftnode = new TreeNode(stoi(str));
                curr->left = leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#")
            {
                curr->right=NULL;
            }
            else 
            {
                TreeNode* rightnode = new TreeNode(stoi(str));
                curr->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));