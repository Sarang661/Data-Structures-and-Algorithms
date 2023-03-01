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
    
    void findMaxDepth(TreeNode*root, int &maxDepth, int currDepth){
        
        if(!root){
            return;
        }
        
        maxDepth = max(maxDepth, currDepth);
        
        findMaxDepth(root->left, maxDepth, currDepth+1);
        findMaxDepth(root->right, maxDepth, currDepth+1);
    }
    
    TreeNode* findSubtree(TreeNode*root, int &maxDepth, int currDepth){
        
        if(!root){
            return NULL;
        }
        
        if(currDepth == maxDepth){
            return root;
        }
        
        TreeNode*l = findSubtree(root->left, maxDepth, currDepth+1);
        TreeNode*r = findSubtree(root->right, maxDepth, currDepth+1);
        
        if(l==NULL){
            return r;
        }
        
        if(r== NULL){
            return l;
        }
        
        return root;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        int maxDepth = 0;
        
        findMaxDepth(root, maxDepth, 0);
        
        return findSubtree(root, maxDepth, 0);
        
    }
};