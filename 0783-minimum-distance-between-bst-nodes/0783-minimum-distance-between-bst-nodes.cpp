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
    int mini = INT_MAX;
    int pre = -1;
    void findMinimumVal(TreeNode*root){
        if(!root){
            return;
        }
        
        findMinimumVal(root->left);
        
        if(pre!= -1){
            mini = min(mini, root->val-pre);
        }
    
        pre = root->val;
        
        findMinimumVal(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        
     
        
        findMinimumVal(root);
        
        return mini;
    }
};