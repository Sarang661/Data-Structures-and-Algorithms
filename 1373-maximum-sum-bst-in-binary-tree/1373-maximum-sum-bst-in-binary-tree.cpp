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
    
    vector<int> findLargestBST(TreeNode*root){
        
        if(root == NULL){
            return {0, INT_MAX, INT_MIN};
        }
        
        vector<int>left = findLargestBST(root->left);
        vector<int>right = findLargestBST(root->right);
        
         
        
        if(left[2] < root->val  &&  root->val < right[1]){
            
             maxi = max({maxi, left[0], right[0], root->val+left[0]+right[0]});
            
            return {root->val+left[0]+right[0], min({left[1],right[1],root->val}), max({left[2],right[2],root->val})};
        }
        
        maxi = max({maxi, left[0], right[0]});
      
        return {-1000, INT_MIN, INT_MAX};
    }
    
public:
    int maxSumBST(TreeNode* root) {
        
        

        findLargestBST(root);
        
        return maxi;
    }
};