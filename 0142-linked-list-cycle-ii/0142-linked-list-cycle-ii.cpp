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
         // unordered_map<ListNode*, bool> visited;
         ListNode* slow = head;
         ListNode* fast = head;
         if(head==nullptr)return NULL;
         while(fast->next && fast->next->next){
             fast=fast->next->next;
             slow=slow->next;
             if(slow==fast)break;
         }
         if(fast->next == nullptr || fast->next->next==nullptr)return NULL;
         fast=head;
         while(fast!=slow){
             fast=fast->next;
             slow=slow->next;
         }
         
         return fast;
    }
};