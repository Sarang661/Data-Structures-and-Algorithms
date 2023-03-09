/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*slow=head;
        ListNode*fast = head;
        ListNode*n =head;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(n!=slow){
                    slow=slow->next;
                    n=n->next;
                }
                return n;
            }
        
        
        }
        return NULL;
    }
};