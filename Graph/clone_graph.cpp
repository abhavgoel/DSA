/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<int,Node*>mp;
void dfs(Node* node , Node* clone)
{
    for(Node* it:node->neighbors)
    {
        if(mp.find(it->val)==mp.end())
        {
            Node* new_clone = new Node(it->val);
            mp[it->val]=new_clone;

            clone->neighbors.push_back(new_clone);

            dfs(it,new_clone);
        }
        else
        {
            clone->neighbors.push_back(mp[it->val]);
        }
    }
}
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;

        Node* clone = new Node(node->val);

        //we need to store the clone nodes, so that while traversing the graph we
        //can attatch the cloned node as a neighbour if required.

        //if we dont store it , then lets say for example - 
        // 1----2, when we have cloned 1 and moved to 2 , then 2 also has 1 
        //as an adjacent ,if we make new clone then grapg would look like this
        // 1----2---1, which doesnt servers our purpose
        // so we need to stored cloned nodes 
        mp[node->val]=clone;
        dfs(node,clone);

        return clone;
    }
};