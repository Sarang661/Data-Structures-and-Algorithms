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
    int len=0;
      ListNode*j;
    ListNode*u;
public:
    Solution(ListNode* head) {
      j=head;
        u=head;
        while(j!=NULL){
            j=j->next;
            len++;
        }
        j=head;
    }
    
    int getRandom() {
        int k =rand()%len;
      j=u;
        for(int i=0;i<k;i++){
            j=j->next;
            
        }
        return j->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */