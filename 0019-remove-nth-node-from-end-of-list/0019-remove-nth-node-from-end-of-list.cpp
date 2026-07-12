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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

       
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

       
        slow->next = slow->next->next;

        return dummy->next;
    }
};



//     ListNode* temp=head;
//         int count=0;
//         while(temp!=NULL){
//          count++;
//           temp = temp->next;
//         }
//      if(count==n){
//         return head->next;
//      }

//  temp = head;

//         for(int i = 1; i < count - n; i++){
//             temp = temp->next;
//         }

//         temp->next = temp->next->next;

//         return head;