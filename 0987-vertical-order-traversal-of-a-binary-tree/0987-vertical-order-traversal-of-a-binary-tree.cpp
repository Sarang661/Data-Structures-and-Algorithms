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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.empty()==false){
           auto c=q.front();
            TreeNode*curr=c.first;
            q.pop();
            int x=c.second.first;
            int y=c.second.second;
            m[x][y].insert(curr->val);
            if(c.first->left!=NULL){
                q.push({c.first->left,{x-1,y+1}});
            }
               if(c.first->right!=NULL){
                q.push({c.first->right,{x+1,y+1}});
            }
        }
        vector<vector<int>>v;
        for(auto x:m){
            vector<int>k;
            for(auto f:x.second){
                k.insert(k.end(),f.second.begin(),f.second.end());
            }
            v.push_back(k);
        }
        return v;
    }
};