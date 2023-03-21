class FindElements {
    unordered_set<int> set;
public:
    void recover(TreeNode* root, int x) {
        if (!root) return;
        root->val = x;
        set.emplace(x);
        recover(root->left, 2 * x + 1);
        recover(root->right, 2 * x + 2);
    }
    
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return set.count(target);
    }
};