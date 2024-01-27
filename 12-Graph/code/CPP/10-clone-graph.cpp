//Link: https://leetcode.com/problems/clone-graph/description/
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
    void dfs(Node* start,unordered_map<Node*,Node*> &m){
        Node* new_node=new Node(start->val);
        m[start]=new_node;
        //visit all the neighours
        for(auto &nbr:start->neighbors){
            //if visited
            if(m.find(nbr)!=m.end()) {
                new_node->neighbors.push_back(m[nbr]);
            }
            else{
                dfs(nbr,m);
                new_node->neighbors.push_back(m[nbr]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> m;
        dfs(node,m);
        return m[node];
    }
};
//
class Solution {
public:
    
    void dfs(Node* actual,Node* clone){
        for(auto nbr:actual->neighbors){
            if(!nodeRegister[nbr->val]){
                Node* newNode=new Node(nbr->val);
                nodeRegister[newNode->val]=newNode;
                clone->neighbors.push_back(newNode);
                dfs(nbr,newNode);
            }else{
                clone->neighbors.push_back(nodeRegister[nbr->val]);
            }
        }
    }
    

    vector<Node*> nodeRegister;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node *clone = new Node(node->val);
        nodeRegister.resize(110);
        nodeRegister[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
    // void dfs(Node* start,unordered_map<Node*,Node*> &m){
    //     Node* new_node=new Node(start->val);
    //     m[start]=new_node;
    //     //visit all the neighours
    //     for(auto &nbr:start->neighbors){
    //         //if visited
    //         if(m.find(nbr)!=m.end()) {
    //             new_node->neighbors.push_back(m[nbr]);
    //         }
    //         else{
    //             dfs(nbr,m);
    //             new_node->neighbors.push_back(m[nbr]);
    //         }
    //     }
    // }
    // Node* cloneGraph(Node* node) {
    //     if(node==NULL) return NULL;
    //     unordered_map<Node*,Node*> m;
    //     dfs(node,m);
    //     return m[node];
    // }
};