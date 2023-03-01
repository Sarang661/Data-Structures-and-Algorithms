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
public:
    vector<TreeNode*> generateTrees(int n) {
        
        return findAllTrees(1, n);
    }
    
    vector<TreeNode*>findAllTrees(int start, int end){
        
        vector<TreeNode*>vec;
        
        if(start > end){
            vec.push_back(NULL);
            return vec;
            
        }
        
        if(start == end){
            vec.push_back(new TreeNode(start));
            return vec;
        }
        
        vector<TreeNode*>ans;
        
        for(int index = start; index <= end; index++){
            
             vector<TreeNode*>left = findAllTrees(start,index-1);
            vector<TreeNode*>right = findAllTrees(index+1, end);
            
            
            
            for(auto curr1:left){
                
                for(auto curr2:right){
                    
                    TreeNode* curr = new TreeNode(index);
                    curr->left = curr1;
                    curr->right = curr2;
                    ans.push_back(curr);
                }
            }
            
            
        }
        
        return ans;
       
    }
};