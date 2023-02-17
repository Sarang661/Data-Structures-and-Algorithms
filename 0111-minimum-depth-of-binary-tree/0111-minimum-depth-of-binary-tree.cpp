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
    
    int mini = INT_MAX;
    void findMinimumDepth(TreeNode* root, int currDepth){
        
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            mini = min(mini, currDepth);
        }
        
        findMinimumDepth(root->left, currDepth+1);
        findMinimumDepth(root->right, currDepth+1);
    }
public:
    int minDepth(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        findMinimumDepth(root, 1);
        
        return mini;
    }
};