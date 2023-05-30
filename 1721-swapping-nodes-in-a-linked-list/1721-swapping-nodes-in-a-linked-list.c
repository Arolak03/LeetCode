/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k){
    int count = 0;
    struct ListNode* index = head; 
    while(index != NULL){
        index =  index -> next;
        count++;
    }
    int other = count - k;
    free(index);
    struct ListNode* one = head;
    struct ListNode* two = head;
    while((k-1)>0){
        one = one -> next;
        k--;
    }
    
    while(other != 0){
        two = two -> next;
        other--;
    }
    int temp = one -> val;
    one -> val = two -> val;
    two -> val = temp;
    return head;
}