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
    int val = INT_MIN;
    int find(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        
       
        int node = root->val;
        
        int l = max(0, find(root->left));
        int r = max(0, find(root->right));
        
        val = max(val, l+node+r);
  
        return max(l+node, r+node);
    }
public:
    int maxPathSum(TreeNode* root) {
        
   
        find(root);
        
        return val;
    }
};