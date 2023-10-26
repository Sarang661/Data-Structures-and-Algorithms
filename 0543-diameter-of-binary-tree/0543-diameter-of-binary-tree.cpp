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
    
    int findDiameter(TreeNode* root, int &maxWidth){
        
        if(root == NULL){
            
            return 0;
        }
        
        int left = findDiameter(root->left, maxWidth);
        int right = findDiameter(root->right, maxWidth);
        
        // storing max diameter after traversing all nodes
        maxWidth = max(maxWidth, left+right);
        
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
     
        // to store max diameter 
        int maxWidth = 0;
        
           // function will return the diameter of the tree
      findDiameter(root, maxWidth);
        
        return maxWidth;
    }
};