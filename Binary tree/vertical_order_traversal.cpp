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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>nodes;//vertical column as first field because , we need in sorted format, ie--> -2,-1,0,1,2


        queue<pair<TreeNode*,pair<int,int>>>q;//{node,{vertical,level}};

        //we assign the vertical column number to nodes while breadth first search and
        //also keep track of their levels
        //in short
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int vertical_col = it.second.first;
            int level = it.second.second;

            nodes[vertical_col][level].push_back(node->val);

            if(node->left)q.push({node->left,{vertical_col-1,level+1}});
            if(node->right)q.push({node->right,{vertical_col+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto i:nodes)
        {
            vector<int>col;
            for(auto j:i.second)//iterator to inner map
            {
                sort(begin(j.second),end(j.second));
                for(auto k:j.second)
                {
                    col.push_back(k);
                }
            }

            ans.push_back(col);
        }
        return ans;
    }
};