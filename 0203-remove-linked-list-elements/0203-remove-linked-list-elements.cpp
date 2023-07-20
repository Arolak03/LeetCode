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
    ListNode* removeElements(ListNode* head, int val) {
         if(head==NULL){
        return head;
    }
    struct ListNode* p=new ListNode(0);
    struct ListNode* q=p;
    p->next=head;
    while(p!=NULL && p->next!=NULL){
        if(p->next->val==val){
            p->next=p->next->next;
        }
        else{
            p=p->next;
        }
    }
    return q->next;
        
    }
};