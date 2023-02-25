/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*>level;
        
        if(!root){
            return root;
        }
        
       Node*prev = NULL;
        level.push(root);
        
        while(!level.empty()){
            
            int size = level.size();
            prev = NULL;
            
            for(int index = 0; index < size; index++){
                
                if(prev != NULL){
                    prev->next = level.front();
                }
                
                  prev = level.front();
                
                if(level.front()->left){
                    level.push(level.front()->left);
                }
                
                if(level.front()->right){
                    level.push(level.front()->right);
                }
                level.pop();
            }
        }
        
        return root;
    }
};