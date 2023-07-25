class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int n = 0;
        ListNode* temp = head;
        
        // Count the number of nodes in the linked list
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int parts = n / k;
        int rem = n % k;
        
        temp = head;
        while (k > 0) {
            int partSize = parts;
            if (rem > 0) {
                partSize++;
                rem--;
            }

            if (partSize == 0) {
                ans.push_back(nullptr);
            } else {
                ans.push_back(temp);
                for (int i = 0; i < partSize - 1; i++) {
                    temp = temp->next;
                }
                ListNode* nextTemp = temp->next;
                temp->next = nullptr;
                temp = nextTemp;
            }
            
            k--;
        }

        return ans;
    }
};
