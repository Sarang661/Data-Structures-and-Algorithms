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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int>indexes;
        
        for(int index= 0; index < inorder.size(); index++){
            indexes[inorder[index]] = index;
        }
        
        return buildCompleteTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, indexes);
    }
    
    TreeNode* buildCompleteTree(vector<int>&inorder, int i1, int i2, vector<int>&postorder, int i3, int i4, map<int,int>&indexes){
        
        if(i1>i2 || i3>i4){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[i4]);
        int dis = indexes[postorder[i4]] - i1;
        
        root->left = buildCompleteTree(inorder, i1, indexes[postorder[i4]]-1,postorder, i3, i3+dis-1, indexes );
        
        root->right = buildCompleteTree(inorder, indexes[postorder[i4]]+1, i2, postorder, i3+dis, i4-1, indexes);
        
        return root;
    }
};