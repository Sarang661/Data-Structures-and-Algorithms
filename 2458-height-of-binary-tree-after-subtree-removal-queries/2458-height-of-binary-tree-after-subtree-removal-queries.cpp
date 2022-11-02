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
   int preh[100001], posth[100001], maxh;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxh = 0; pre(root, 0);
        maxh = 0; post(root, 0);
        vector<int> res;
        for (int q : queries)
            res.push_back(max(preh[q], posth[q]));
        return res;
    }

    void pre(TreeNode* root, int h) {
        if (!root) return;
        preh[root->val] = maxh;
        maxh = max(maxh, h);
        pre(root->left, h + 1);
        pre(root->right, h + 1);
    }

    void post(TreeNode* root, int h) {
        if (!root) return;
        posth[root->val] = maxh;
        maxh = max(maxh, h);
        post(root->right, h + 1);
        post(root->left, h + 1);
    }
};