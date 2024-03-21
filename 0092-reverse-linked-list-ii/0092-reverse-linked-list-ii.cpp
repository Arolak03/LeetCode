class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* ans =head;
        ListNode* prev = nullptr;
        int leftnode = 1;
        ListNode* prevleft = nullptr;
        while(head && leftnode<left){
            prevleft = head;
            head=head->next;
            ++leftnode;
        }
       ListNode* leftstart = head;
       while(head && right-left>=0){
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
            --right;
       }
        leftstart->next = head;
       if(prevleft!=nullptr){
        prevleft->next = prev;
        return ans;
       }
       return prev;
    }
};