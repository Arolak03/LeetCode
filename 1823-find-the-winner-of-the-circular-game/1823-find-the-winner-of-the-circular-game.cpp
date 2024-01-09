class Solution {
public:
    class LList{
        
        public:
        int val;
        LList* prev;
        LList* next;
        LList(int x){
            val=x;
            prev=NULL;
            next=NULL;
        }
    };
    
    
    int findTheWinner(int n, int k) {
        if(k==1)return n;
        LList* head= new LList(1);
        // LList ans = new LList(1);
        LList* tail=head;
        for(int i=2;i<=n;i++){
            LList* temp=new LList(i);
            tail->next=temp;
            temp->prev=tail;
            tail=tail->next;
            // head->next=temp;
            // temp->prev=temp;
            // tail=temp;
            // temp=temp->next;
            
        }
        // cout<<head->val;
        tail->next=head;
        head->prev=tail;
        LList* curr=head;
        LList* a=head;
        while(curr->next != curr){
            for (int i = 1; i < k-1; i++) {
                curr = curr->next;
            }
            a=curr->next->next;
            a->prev=curr;
            curr->next=a;
            curr=curr->next;
        }
        return curr->val;
    }
};