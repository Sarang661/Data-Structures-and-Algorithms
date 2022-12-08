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
    int index = 0;
    
    void findLeafSequence(TreeNode * root, vector<int>&leafSeq){
        if(root==NULL){
            return;
        }
    
        
        findLeafSequence(root->left,leafSeq);
        
           if(root->left == NULL && root->right == NULL){
            leafSeq.push_back(root->val);
        }
        
        findLeafSequence(root->right,leafSeq);
    }
    
    bool  checkLeafSequence(TreeNode * root, vector<int>&leafSeq){
        if(root==NULL){
            return true;
        }
    
        
       bool flag1 =  checkLeafSequence(root->left,leafSeq);
        
       
        if(root->left == NULL && root->right == NULL){
           
        
            if(index>=leafSeq.size() || leafSeq[index] != root->val){
                    
             return false;
                
            }
            
            if(index<leafSeq.size()){
                 leafSeq[index] = -1;
            }
                index++;
        }
        
         bool flag2 = checkLeafSequence(root->right,leafSeq);
        
        
        if(flag1 && flag2){
             return true;
        }
       return false;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int>leafSeq;
        
        findLeafSequence(root1,leafSeq);
        
        bool flag = checkLeafSequence(root2,leafSeq);
        
        
        for(int i=0;i<leafSeq.size();i++){
            if(leafSeq[i]!=-1){
                flag=false;
                break;
            }
        }
        
        
        if(flag){
            
          return true;
        }
        else{
            return false;
        }
    }
};