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

    int checkHeightBalanced(TreeNode*root, bool &check){
        
        if(!root){
            
            return 0;
        }
        
        
        // traversing the left and right subtree
        int left = checkHeightBalanced(root->left, check);
        int right = checkHeightBalanced(root->right, check);
        
        // checking if current root of the tree is height balanced or not
        if(abs(left-right) > 1){
            
            check = false;
        }
        
        return 1 + max(left, right);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        
        bool check = true;
        
        // function to check if tree is height balanced or not
        
        checkHeightBalanced(root, check);
        
        return check;
    }
};