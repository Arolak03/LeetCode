/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* index = head;
    int count = 0;
    
    while (index != NULL) {
        count++;
        index = index->next;
    }
    
    if (count % 2 == 0) {
        count = count / 2;
    } else {
        count = count - 1;
        count = count / 2;
    }
    
    if(count==0){
        return NULL;
    }
    struct ListNode* ans = head;
    count--;
    while(count){
        count--;
        ans = ans->next;
    }
    ans->next = ans->next->next;
    return head;
}