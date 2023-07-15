
/*
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=-1;
        while(q.empty()==false)
        {
            int sz = q.size();
            int minIndexOfLevel = q.front().second;
            int last,first;
            for(int i=0;i<sz;i++)
            {
                auto it=q.front();
                q.pop();

                TreeNode* curr = it.first;
                int index = it.second - minIndexOfLevel;

                if(i==0)first=index;
                if(i==sz-1)last = index;

                if(curr->left)
                {
                    q.push({curr->left,(long long)index*2+1});
                }
                if(curr->right)
                q.push({curr->right,(long long)index*2+2});

            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};

