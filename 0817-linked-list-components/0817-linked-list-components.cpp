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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s;
        for(auto it: nums) s.insert(it);
        bool conn=false;
        int total=0;
        while(head){
            int val= head->val;
            if(s.count(val)&& conn==false){
                conn=true;
                total++;
            }
            else if(s.count(val)==0&& conn==true)conn=false;
            head=head->next;

        }
        return total;
    }
    
};