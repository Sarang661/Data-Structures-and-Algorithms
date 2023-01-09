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
    
    void findPreOrderTraversal(vector<int>&preOrder, TreeNode* root){
        
        if(root == NULL){
            return;
        }
        
        preOrder.push_back(root->val);
        
        findPreOrderTraversal(preOrder, root->left);
        
        findPreOrderTraversal(preOrder, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>preOrder;
        
        findPreOrderTraversal(preOrder, root);
        
        return preOrder;
    }
};