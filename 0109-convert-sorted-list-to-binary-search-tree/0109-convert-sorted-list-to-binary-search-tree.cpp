/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
 TreeNode* createBST(ListNode*start, ListNode*end){
     
     
     if(start==end){
         return NULL;
     }
     
        ListNode*mid = start;
        ListNode*fast = start;
     
         while(fast!=end && fast->next!=end){
            
            mid = mid->next;
            fast = fast->next->next;
        }
     
    TreeNode*curr = new TreeNode(mid->val);
     
       curr->left =  createBST(start, mid);
       curr->right = createBST(mid->next, end);
     
     return curr;
     
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        

        
        ListNode*mid = head;
        ListNode*fast = head;
        int currLen = 0;
        
     
     return    createBST(head, NULL);
        
        
    }
};