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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode*curr = head;
        
        while(curr!= NULL){
            
            ListNode* curr2 = curr;
            
            while(curr->next!= NULL && curr->val==(curr->next->val)){
                
                curr = curr->next;
            }
            
            curr2->next = curr->next;
            curr = curr->next;
        }
        return head;
    }
};