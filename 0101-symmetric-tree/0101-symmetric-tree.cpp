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
    bool findIfTreeIsSymmetric(TreeNode*node1, TreeNode*node2){
        
        if(node1== NULL || node2 == NULL){
            return node1 == node2;
        }
        
        if(node1->val != node2->val){
            return false;
        }
        
        return findIfTreeIsSymmetric(node1->right, node2->left) && findIfTreeIsSymmetric(node1->left, node2->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        return findIfTreeIsSymmetric(root->left, root->right);
    }
};