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
    
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
   
    ListNode* solve(ListNode* first, ListNode* second){
        if(first==NULL){
            return second;
        }
        if(second==NULL){
            return first;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(first!=NULL && second!=NULL){
            if(first->val<second->val){
                temp->next = first;
                temp=temp->next;
                first=first->next;
            }
            else{
                temp->next = second;
                temp=second;
                second=second->next;
            }
        }
        while(first!=NULL){
            temp->next = first;
            temp=first;
            first=first->next;
        }
        while(second!=NULL){
            temp->next = second;
            temp=second;
            second=second->next;
        }
        // ans = temp;
        // ans= ans->next;
        cout<<temp->val;
        //temp last m chala gya h
        return ans->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //split
        ListNode* mid = findMid(head);
        // ListNode* temp = head;
        ListNode* first = head;
        ListNode* second = mid->next;
        mid->next=NULL;
        //merge and sort;
        first = sortList(first);
        second = sortList(second);
        ListNode* result = solve(first,second);
        // if (first->val <= second->val) {
            // return first;
        // }
        return result;
    }
};