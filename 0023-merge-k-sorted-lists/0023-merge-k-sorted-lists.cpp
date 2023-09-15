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
    
    class compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; 
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
            
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            ListNode* ans = pq.top();
            pq.pop();
            if(ans->next){
                pq.push(ans->next);
            }
            if(head==NULL){
                head= ans;
                tail=ans;
            }
            else{
                tail->next=ans;
                tail=ans;
            }
            
        }
        return head;
    }
};