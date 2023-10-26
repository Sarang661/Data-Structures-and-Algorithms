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
    
    int findMaxPathSum(TreeNode* root, int &maxSum){
        
        if(!root){
            
            return 0;
        }
        
        // traversing the left and right subtree
        int left = max(0,findMaxPathSum(root->left, maxSum));
        int right = max(0,findMaxPathSum(root->right, maxSum));
        
        
        // storing maximum after each step;
        maxSum = max(maxSum, left + right + root->val);
        
        return (root->val + max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        
        
        int maxSum = INT_MIN;
        
        //function to find maximum path sum
        
        findMaxPathSum(root, maxSum);
        
        return maxSum;
    }
};