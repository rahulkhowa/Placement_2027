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
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        Node* start = node;
        mp[start] = new Node(start->val,{});//deep copy
        queue<Node*>q;
        q.push(start);
        while(!q.empty()){
            auto u = q.front();q.pop();
            for(auto v:u->neighbors){
                if(!mp.count(v)){
                    mp[v] = new Node(v->val,{});//deep copy
                    q.push(v);
                }
                mp[u]->neighbors.push_back(mp[v]);
            }
        }
        return mp[node];
    }
};