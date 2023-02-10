/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        
        string s = "";
        if(!root){
            return s;
        }
        while(!q.empty()){
            
            if(q.front() == NULL){
                s+="#,";
            }
            else{
                   s+= (to_string(q.front()->val)+",");
            }
              
            if(q.front()!=NULL){
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
             q.pop();
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
         if(data.size() == 0){
            return NULL;
        }
        stringstream s(data);
        string curr = "";
        
        getline(s,curr,',');
        
        TreeNode* root = new TreeNode(stoi(curr));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode*node = q.front();
            q.pop();
            getline(s,curr,',');
            
            if(curr=="#"){
                node->left = NULL;
            }
            else{
                node->left = new TreeNode(stoi(curr));
                q.push(node->left);
            }
            
            getline(s,curr,',');
            
            if(curr=="#"){
                node->right = NULL;
            }
            else{
                node->right = new TreeNode(stoi(curr));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));