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
    
    void insertAtTail(ListNode* &head, ListNode* &tail, int value){
        ListNode* temp = new ListNode(value);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newh = NULL;
        ListNode* newt = NULL;
        int carry =0;
        while(l1!=NULL && l2!=NULL){
            int sum = carry+l1->val+l2->val;
            int digit=sum%10;
           
            insertAtTail(newh,newt,digit);
            l1=l1->next;
            l2=l2->next;
             carry=sum/10;
        }
        while(l1!=NULL){
            int sum = carry+l1->val;
            int digit=sum%10;
            carry=sum/10;
            insertAtTail(newh,newt,digit);
            l1=l1->next;
            // l2=l2->next;
        }
        while(l2!=NULL){
            int sum = carry+l2->val;
            int digit=sum%10;
            carry=sum/10;
            insertAtTail(newh,newt,digit);
            // l1=l1->next;
            l2=l2->next;
        }
        while(carry!=0){
            int sum = carry;
            int digit=sum%10;
            carry=sum/10;
            insertAtTail(newh,newt,digit);
            // l1=l1->next;
            // l2=l2->next;
        }
        return newh;
            
    }
};