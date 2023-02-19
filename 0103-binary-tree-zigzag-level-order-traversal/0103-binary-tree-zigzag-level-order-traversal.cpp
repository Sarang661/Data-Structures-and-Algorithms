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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int currLevel = 0;
        queue<TreeNode*>level;
        
        level.push(root);
        
        vector<vector<int>>ans;
        
        
        if(!root){
            return ans;
        }
        
        while(!level.empty()){
            
            int size = level.size();
            vector<int>curr;
            
            for(int index = 0; index < size; index++){
                
                TreeNode*currNode = level.front();
                level.pop();
                
                curr.push_back(currNode->val);
                
                if(currNode->left){
                    level.push(currNode->left);
                }
                
                  if(currNode->right){
                    level.push(currNode->right);
                }
            }
            
            if(currLevel%2){
                reverse(curr.begin(), curr.end());
            }
            ans.push_back(curr);
            currLevel++;
        }
        
        return ans;
    }
};