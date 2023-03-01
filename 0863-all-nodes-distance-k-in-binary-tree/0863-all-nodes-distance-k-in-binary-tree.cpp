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

private:

    void findParent(map<TreeNode*,TreeNode*>&parent, TreeNode*root, TreeNode*p){
        
        if(!root){
            return;
        }
        
        parent[root] = p;
        
        findParent(parent, root->left, root);
        findParent(parent, root->right, root);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        map<TreeNode*, TreeNode*>parent;
        
        findParent(parent, root, NULL);
        
        queue<pair<TreeNode*,int>>nodes;
        
        nodes.push({target, 0});
        
        vector<int>ans;
        set<int>visited;
        visited.insert(target->val);
        
        while(!nodes.empty()){
            
            TreeNode*curr = nodes.front().first;
            int steps = nodes.front().second;
            
            nodes.pop();
            
            if(steps==k){
                
                ans.push_back(curr->val);
                continue;
            }
            
            if(curr->left && visited.find(curr->left->val)==visited.end()){
                nodes.push({curr->left, steps+1});
                visited.insert(curr->left->val);
            }

             if(curr->right && visited.find(curr->right->val)==visited.end()){
                nodes.push({curr->right, steps+1});
                  visited.insert(curr->right->val);
            }
            
             if(parent[curr]!=NULL && visited.find(parent[curr]->val)==visited.end()){
                 
                nodes.push({parent[curr], steps+1});
                 visited.insert(parent[curr]->val);
            }
        }
        
        return ans;
        
    }
};