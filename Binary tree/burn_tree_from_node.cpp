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
    TreeNode* mapParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,int start)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode *startNode;
        while(q.empty()==false)
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val==start)
            startNode = curr;

            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left] = curr;

            }
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right] = curr;
                
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* startNode = mapParents(root,parent,start);

        queue<pair<TreeNode*,int>>q;
        map<TreeNode* ,int>vis;
        int time = 0;
        //start node needed , but we are given start value
        q.push({startNode,0});
        vis[startNode]=1;
        while(q.empty()==false)
        {
            TreeNode *curr=q.front().first;
            int d = q.front().second;
            q.pop();
            time = d;

            if(curr->left && vis[curr->left]==0)
            {
                q.push({curr->left,d+1});
                vis[curr->left]=1;

            }
            if(curr->right && vis[curr->right]==0)
            {
                q.push({curr->right,d+1});
                vis[curr->right]=1;
                
            }
            if(parent.find(curr)!=parent.end() && vis[parent[curr]]==0)
            {
                q.push({parent[curr],d+1});
                vis[parent[curr]]=1;
            }

        }
        return time;
    }
};