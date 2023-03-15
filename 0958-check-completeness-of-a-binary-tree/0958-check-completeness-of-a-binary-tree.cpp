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
    bool isCompleteTree(TreeNode* root) {
       
       
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,NULL});
        vector<int>traversal;
        traversal.push_back(root->val);
        
        while(!q.empty()){
            
            int size = q.size();
       
                for(int index = 0; index < size; index++){
                    
                    TreeNode*temp = q.front().first;
                    q.pop();
                    
                   
                    
                    if(temp->left){
                        q.push({temp->left,temp});
                        traversal.push_back(temp->left->val);
                    }
                    else{
                         traversal.push_back(-1);
                    }
                  
                     if(temp->right){
                        q.push({temp->right, temp});
                          traversal.push_back(temp->right->val);
                    }
                    else{
                          traversal.push_back(-1);
                    }
                   
                }
            
       
        }
        
        int prev = 0;
        for(int index = 0; index < traversal.size(); index++ ){
            
            if(traversal[index] != -1 && prev!=0){
                return false;
            }
            
              if(traversal[index] == -1 ){
                prev = -1;
            }
        }
        
        
        return true;
    }
};