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
    void findNodes(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        findNodes(root->left,ans);
        ans.push_back(root->val);
        findNodes(root->right,ans);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
        vector<int>ans;
        vector<vector<int>>finalAns;
        findNodes(root,ans);
        int n = q.size();
      
        
        for(int i=0;i<n;i++){
            int x = 0;
            int y = 0;
            auto it = upper_bound(ans.begin(),ans.end(),q[i]);
            it--;
            if(it<ans.begin()){
                x = -1;
            }
            else{
                x = *it;
            }
            
            it = lower_bound(ans.begin(),ans.end(),q[i]);
            if(it==ans.end()){
                y = -1;
            }
            else{
                y= *it;
            }
            finalAns.push_back({x,y});
            
        }
        
        
        return finalAns;
    }
};