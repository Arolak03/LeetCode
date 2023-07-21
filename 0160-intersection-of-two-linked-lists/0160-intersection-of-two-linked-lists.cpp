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
    
    int len(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int count=0;
        count = 1 + len(head->next);
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* temp1 = headA;
        // ListNode* temp2=headB;
        if(!headA || !headB){
            return NULL;
        }
        int lenA = len(headA);
        int lenB = len(headB);
        if(lenA>lenB){
            while(lenA>lenB){
                headA=headA->next;
                lenA--;

            }
        }
        else if(lenA<lenB){
            while(lenA<lenB){
                headB=headB->next;
                lenB--;
                 
            }
        }

        
        while(headA!=NULL && headB!=NULL){
            if(headA == headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};