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
  private:
    
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev=NULL;
        ListNode* forw =NULL;
        while(curr){
            forw = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    
    void insertAtTail(ListNode* &head, ListNode* &tail, int value){
        ListNode* temp = new ListNode(value);
        if(head==NULL){
            head=temp;
            tail=temp;
            // return ;
        }
        //not null
        else{
            tail->next = temp;
            tail=temp;
        }
    }
    
    ListNode* add(ListNode* first, ListNode* sec){
        ListNode* firstH = NULL;
        ListNode* secH=NULL;
        int carry =0 ;
        while(first!=NULL || sec!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL){
                val1=first->val;
            }
            int val2=0;
            if(sec!=NULL){
                val2=sec->val;
            }
            int sum = carry + val1+val2;
            int digit=sum%10;
            insertAtTail(firstH,secH,digit);
            carry = sum/10;
            if(first){
                first=first->next;
            
            }
            if(sec){
                sec=sec->next;
            }
        }
        return firstH;
    }
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2=reverse(l2);
        //both are revered
        //heads are prev1 and prev2
        ListNode* ans = add(l1,l2);
        ans=reverse(ans);
        return ans;
        
    }
};