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
  ListNode* head;// member variable
    Solution(ListNode* head) {
      this->head=head; //Store the parameter head inside the object's head.
      //we need head because both varobale is head 
    }
    
    int getRandom() {
   int count = 0;

        ListNode* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        int randomIndex = rand() % count;//gives us a random index between:0 and count-1
        temp = head; //reset head;

      
        for(int i = 0; i < randomIndex; i++) {
            temp = temp->next;
        }

        return temp->val;



    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */