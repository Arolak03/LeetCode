/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//  struct ListNode* traverse(struct ListNode* head){
//      struct ListNode* ptr = head;
//      while(ptr -> next != NULL){
//          printf("%d", ptr);
//          ptr = ptr -> next;
//      }
//  };
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p = head;
        int i = 0;
        while(p -> next != NULL){
            p = p-> next;
            i++;
        }
        struct ListNode* q = head;
        if (i%2==0){
        
        i = (i/2);
        }
        else{
            i = i-1;
            i = i/2;  
            i = i+1;  
        }
        while(i != 0){
            q = q -> next;
            i--;
        }
        // q = q-> next;
        return q;

}