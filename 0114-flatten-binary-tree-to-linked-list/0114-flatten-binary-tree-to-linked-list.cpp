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
    TreeNode*prev = NULL;
    
    void flattenTreeToList(TreeNode*root){
        
        if(root == NULL){
            return;
        }
        
        flattenTreeToList(root->right);
        flattenTreeToList(root->left);
        
        root->left = NULL;
        root->right = prev;
        prev = root;
        
    }
public:
    void flatten(TreeNode* root) {
        
        flattenTreeToList(root);
    }
};