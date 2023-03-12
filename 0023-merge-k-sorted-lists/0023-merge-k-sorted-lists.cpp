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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        vector<int>v;
        for(int i=0;i<lists.size();i++){
            ListNode*k=lists[i];
            while(k!=NULL){
                v.push_back(k->val);
                k=k->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode*head;
        if(v.empty()==false){
     head=new ListNode(v[0]);
        }
    ListNode*temp=head;
        for(int i =1;i<v.size();i++){
         
            head->next =new ListNode(v[i]);
            head=head->next;
        }
        if(v.size()==0){
            return NULL;
        }
        return temp;
    }
};