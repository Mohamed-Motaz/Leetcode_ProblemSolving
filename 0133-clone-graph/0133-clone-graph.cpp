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
    unordered_map<int, Node*> vis;

    Node* cloneGraph(Node* original) {
        if (!original) return NULL;
        // cout << "val: " << original->val << " neighbors sz: " << original->neighbors.size() << " neighbors vals: ";
        // for (int i = 0; i < original->neighbors.size(); i++){
        //     cout << original->neighbors[i]->val << " ";
        // }
        // cout << endl;

        Node* clone = new Node(original->val);
        vis[clone->val] = clone;

        if (original->neighbors.size() == 0){
            return clone;
        }
        vector<Node*> v = vector<Node*>();
        for (int i = 0; i < original->neighbors.size(); i++){
            if (vis.find(original->neighbors[i]->val) == vis.end())
                v.push_back(cloneGraph(original->neighbors[i]));
            else
                v.push_back(vis[original->neighbors[i]->val]);
        }

        clone->neighbors = v;
        return clone;
    }
};