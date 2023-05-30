/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    struct ListNode* one = head;
    struct ListNode* two = head;
    while(one && one -> next){
        one = one -> next -> next;
        two = two -> next;
        if (one == two){
            return true;
        }
        // break;
    }
    return false;
}