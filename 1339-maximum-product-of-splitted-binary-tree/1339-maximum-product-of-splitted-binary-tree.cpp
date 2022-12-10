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
int mod = 1e9 +7;
    
private:
    
    long long findMaxSum(TreeNode*root, long long &maxSum, long long &totalSum){
        
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            
            return root->val;
        }
        
        
        
        long long leftSum = findMaxSum(root->left, maxSum, totalSum);
        long long rightSum = findMaxSum(root->right, maxSum, totalSum);
        long long node = root->val;

        long long currSum = totalSum - leftSum - rightSum - root->val;
            
        // cout<<node<<" "<<leftSum<<" "<<rightSum<<" "<<prevSum<<"\n";
        maxSum = max({maxSum,((leftSum+node+currSum)*rightSum), (leftSum*(rightSum+node+currSum))});
            
        return leftSum + rightSum + node;
        
    }
    
    void findTotalSum(TreeNode*root, long long &totalSum){
        
        if(root==NULL){
            
            return;
        }
        
        findTotalSum(root->left, totalSum);
        totalSum += root->val;
         findTotalSum(root->right, totalSum);
    }
public:
    int maxProduct(TreeNode* root) {
        
        long long maxSum = 0;
        long long prevVal = 0;
        long long totalSum = 0;
        
        findTotalSum(root, totalSum);
        
        findMaxSum(root, maxSum, totalSum);
        
        return maxSum%mod;
    }
};