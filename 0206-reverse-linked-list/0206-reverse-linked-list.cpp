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
  ListNode* solve(ListNode* curr, ListNode* prev) {
        if (curr == nullptr) return prev;
        ListNode* forw = curr->next;
        curr->next = prev;
        return solve(forw, curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        return solve(curr, prev);
          // Update to return the new head of the reversed list
    }
};