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
    string ans = "";
    int sum = 0;
    
    void findSum(TreeNode* root){
        
        if(!root){
            return;
        }
        
        if(root->left==NULL && root->right == NULL){
            ans+=to_string(root->val);
            sum+=stoi(ans);
            ans.pop_back();
            return;
        }
        
        ans += to_string(root->val);
        findSum(root->left);
        findSum(root->right);
        ans.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        
        findSum(root);
        
        return sum;
    }
};