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
    
    bool findIsSameTree(TreeNode* p, TreeNode* q){
        
        if(p == NULL && q == NULL){
            
            return true;
        }
        
        if((p == NULL && q != NULL) || (p != NULL && q == NULL) || (p->val != q->val)){
            
            return false;
        }
        
        bool leftHalf = findIsSameTree(p->left, q->left);
        bool rightHalf = findIsSameTree(p->right, q->right);
        
        return leftHalf && rightHalf;
        
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
       return  findIsSameTree(p, q);
    }
};