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
    void dfs(Node*node,vector<Node*>&vi,Node*copy){
    vi[copy->val]=copy;
        for(auto x:node-> neighbors){
            if(vi[x->val]==NULL){
                Node* c=new Node(x->val);
                copy-> neighbors.push_back(c);
                dfs(x,vi,c);
            }
            else{
                copy-> neighbors.push_back(vi[x->val]);
            }
        }
    
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return node;
        }
        
     
        vector<Node*>vi(10000,NULL);
        Node*copy=new Node(node->val);
        dfs(node,vi,copy);
            return copy;
    }
};