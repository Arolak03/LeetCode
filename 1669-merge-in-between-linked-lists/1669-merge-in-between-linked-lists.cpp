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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail1=list1;
        ListNode* prev=new ListNode(-1);
        // tail1=list1;
        int temp=a;
        while(a>0){
            prev=tail1;
            tail1=tail1->next;
            a--;
        }
        ListNode* tail2=tail1;
        // tail2=tail1;
        int x=b-temp;
        while((x--)>0){
            tail2=tail2->next;
        }
        prev->next=list2;
        while(prev->next){
            prev=prev->next;
        }
        prev->next=tail2->next;
            
        return list1;
    }
};