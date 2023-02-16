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
    
    int maxi = 0;
    
    void findMaxDepth(TreeNode*root, int curr){
        
        if(!root){
            return;
        }
      maxi = max(maxi, curr);
        
        findMaxDepth(root->left, curr+1);
         findMaxDepth(root->right, curr+1);
    }
public:
    int maxDepth(TreeNode* root) {
        
        findMaxDepth(root, 1);
        
        return maxi;
    }
};