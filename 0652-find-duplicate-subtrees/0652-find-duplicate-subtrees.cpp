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
    vector<TreeNode*>ans;
    string dfs(TreeNode*root, map<string,int>&freq){
        
        if(!root){
            return "#";
        }
        
       string curr = dfs(root->left, freq) +"," + dfs(root->right, freq) + "," + to_string(root->val);
        
        freq[curr]++;
        
        if(freq[curr]==2){
            ans.push_back(root);
        }
        return curr;
        
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        
        map<string,int>freq;
        
        dfs(root, freq);
        
        
        
        
        return ans;
    }
};