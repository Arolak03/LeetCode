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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // ListNode* end=head;
        ListNode* start=new ListNode(0,head);
        ListNode* temp=start;
        // start->next=head;
        // ListNode* temp=start;
        // ListNode* ans=temp;
        // start=start->next;
        while(start!=NULL){
            int sum=0;
            ListNode* end=start->next;
            while(end!=NULL){
                sum+=end->val;
                if(sum==0){
                    // temp->next=end->next;
                    start->next=end->next;
                    // temp=temp->next;
                }
                end=end->next;
            }
            start=start->next;
        }
        return temp->next;
    }
};