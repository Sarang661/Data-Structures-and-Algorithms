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
    
    vector<int> findNodes(TreeNode* root, int &numNodes){
        
        if(!root){
            
            return {0,0};
        }
        
     vector<int> left = findNodes(root->left, numNodes);
     vector<int> right = findNodes(root->right, numNodes);
        
        int totalNodes = left[0] + right[0] + 1;
        
        int sumNodes = left[1] + right[1] + root->val;
        
    if(sumNodes/totalNodes == root->val){
        
        numNodes++;
    } 
        return {1+left[0] + right[0], sumNodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        
        int numNodes = 0;
        
     findNodes(root, numNodes);
        
        
        return numNodes;
    }
};