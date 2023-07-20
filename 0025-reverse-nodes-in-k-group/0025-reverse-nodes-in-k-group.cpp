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
    
    
    void reverse(ListNode* start, ListNode* end){
        ListNode* prev  = NULL;
        ListNode* curr = start;
        ListNode* n = start->next;
        while(prev != end){
            curr -> next = prev;
            prev = curr;
            curr = n;
             if(n!=NULL){
                n=n->next;
            }
        }
       
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        if(head==NULL || head->next==NULL || k==1){
            return head;
        }
        ListNode* start=head;
        ListNode* end=head;
        int increase = k-1;
        while(increase--){
            end = end->next;
            if(end==NULL)return head;
        }
        ListNode* newHead = reverseKGroup(end->next,k);
        reverse(start,end);
        start->next=newHead;
        return end;
            
    }
};