/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void linkParents(TreeNode* root,map<TreeNode*,TreeNode*>&parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

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
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        linkParents(root,parent);

        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        vector<int>ans;
        map<TreeNode*,int>vis;
        vis[target]=1;
        while(q.empty()==false)
        {
            int sz = q.size();

            for(int i=0;i<sz;i++)
            {
                TreeNode* curr = q.front().first;
                int d = q.front().second;
                q.pop();

                if(d==k)
                ans.push_back(curr->val);
                else if(d>k)
                break;

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
        }
        return ans;
    }
};