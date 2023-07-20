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
    bool isPalindrome(ListNode* head) {
        std::vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        std::vector<int> revarray = arr;
        std::reverse(revarray.begin(), revarray.end());

        for (int i = 0; i < arr.size(); i++) {
            if (revarray[i] != arr[i]) {
                return false;
            }
        }
        return true;
    }
};
