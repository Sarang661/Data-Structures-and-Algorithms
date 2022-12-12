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
    int val = 0;
    int find(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            val = max({val,root->val} );
            return max({root->val,0});
        }
        int node = root->val;
        int l = find(root->left);
        int r = find(root->right);
        
        val = max({val, l+node+r});
  
        return max({l+node, r+node, node,0});
    }
public:
    int maxPathSum(TreeNode* root) {
        
        val = root->val;
        find(root);
        
        return val;
    }
};