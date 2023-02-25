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
    ListNode* sortList(ListNode* head) {
        
        map<int,vector<ListNode*>>nodes;
        
        if(!head){
            return head;
        }
        
        ListNode*curr = head;
        
        while(curr!= NULL){
            
            nodes[curr->val].push_back(curr);
            
            curr = curr->next;
        }
        
        ListNode*prev = new ListNode(0);
        
        ListNode*newHead = (*nodes.begin()).second[0];
        
        for(auto curr:nodes){
            
            for(auto num: nodes[curr.first]){
                prev->next = num;
                prev = num;
            }
         
        }
        
        prev->next = NULL;
        return newHead;
    }
};