class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
//     if (left == right) return head; // Handle left == right case

//     // Find the node before the leftmost node to reverse
//     ListNode* prevLeft = nullptr;
//     ListNode* curr = head;
//     for (int i = 1; i < left; ++i) {
//       if (!curr) return head; // Early return if list is shorter than `left` nodes
//       prevLeft = curr;
//       curr = curr->next;
//     }

//     // Find the rightmost node to reverse
//     ListNode* rightNode = curr;
//     for (int i = left; i <= right; ++i) {
//       if (!rightNode) return head; // Early return if list is shorter than `right` nodes
//       rightNode = rightNode->next;
//     }

//     // Reverse the sublist in-place
//     ListNode* prev = nullptr;
//     ListNode* next = nullptr;
//     while (curr != rightNode) {
//       next = curr->next;
//       curr->next = prev;
//       prev = curr;
//       curr = next;
//     }

//     // Connect the reversed sublist to its surroundings
//     if (prevLeft) {
//       prevLeft->next = prev;
//     } else {
//       head = prev; // If left == 1, update head
//     }
//     rightNode->next = curr;

//     return head;
      vector<ListNode*> v;
      ListNode* temp=head;
      
      while(temp){
          v.push_back(temp);
          temp=temp->next;
      }
      reverse(v.begin()+left-1, v.begin()+right);
      ListNode* ans=new ListNode(v[0]->val);
      temp=ans;
      for(int i=1;i<v.size();i++){
          ListNode* nn=new ListNode(v[i]->val);
          ans->next=nn;
          ans=nn;
      }
      return temp;
  }
};
