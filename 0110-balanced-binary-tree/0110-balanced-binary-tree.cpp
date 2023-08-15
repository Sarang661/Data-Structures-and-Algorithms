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
    
private:
    
    bool isHeightBalanced = true;
    
    int heightBalanced(TreeNode* root){
        
        if( root == NULL){
            
            return 0;
        }
        
        int leftSubtreeHeight = heightBalanced(root->left);
        int rightSubtreeHeight = heightBalanced(root->right);
        
        if(abs(leftSubtreeHeight - rightSubtreeHeight) > 1){
            
            isHeightBalanced = false;
        }
        
        return 1 + max(leftSubtreeHeight,  rightSubtreeHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        
        
       heightBalanced(root);
        
        return isHeightBalanced;
    }
};