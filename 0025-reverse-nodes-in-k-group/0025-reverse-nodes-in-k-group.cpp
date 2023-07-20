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
    pair<ListNode*, ListNode*> reverseSubPart(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* cur = start;
        ListNode* future = cur->next;
        while (cur->next && cur != end) {
            cur->next = prev;
            prev = cur;
            cur = future;
            future = cur->next;
        }
        cur->next = prev;
        ListNode* ptr = cur;
        while (ptr->next) {
            ptr = ptr->next;
        }
        return {cur, ptr};
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }

        ListNode* start = head;
        ListNode* end = head;
        for (int i = 0; i < k - 1; ++i) {
            end = end->next;
        }
        ListNode* res = end;
        ListNode* prev = nullptr;

        start = head;
        end = head;
        while (start) {
            for (int i = 0; i < k - 1; ++i) {
                if (end == nullptr) {
                    break;
                }
                end = end->next;
            }
            if (end == nullptr) {
                break;
            }

            ListNode* temp = end->next;
            auto [newhead, newend] = reverseSubPart(start, end);
            newend->next = temp;
            if (prev != nullptr) {
                prev->next = newhead;
            }
            prev = newend;
            start = end = newend->next;
        }
        return res;
    }
};
