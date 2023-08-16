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
    
    void checkPathSum(TreeNode* root, int targetSum, bool &ans, int currSum){
        
        if(root == NULL){
            return;
        }
        
        if(root-> left == NULL && root-> right == NULL){
            
            currSum = currSum + root->val;
            
            if(currSum == targetSum){
                
                ans = true;
                
            }
        }
        
        checkPathSum(root->left, targetSum , ans, currSum + root->val);
        checkPathSum(root->right, targetSum , ans, currSum + root->val);
        
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool ans = false;
        int currSum = 0;
        
        checkPathSum(root, targetSum, ans, currSum);
        
        return ans;
        
    }
};