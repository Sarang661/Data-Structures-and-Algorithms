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
   
    void findAllPaths(TreeNode*root, vector<string>&ans, string curr){
        
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            
            curr +=to_string(root->val);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }
        
        curr+=to_string(root->val)+"->";
        findAllPaths(root->left, ans, curr);
        findAllPaths(root->right, ans, curr);
     
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        
        findAllPaths(root, ans, "");
        
        return ans;
    }
};