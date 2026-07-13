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
    ListNode* partition(ListNode* head, int x) {

        ListNode smallDummy(-1);
        ListNode largeDummy(-1);

        ListNode* smallTail = &smallDummy;
        ListNode* largeTail = &largeDummy;

        while (head) {

            if (head->val < x) {
                smallTail->next = head;     // Attach current node
                smallTail = head;           // Move tail
            }
            else {
                largeTail->next = head;     // Attach current node
                largeTail = head;           // Move tail
            }

            head = head->next;
        }

    
        largeTail->next = NULL;

    
        smallTail->next = largeDummy.next;

        return smallDummy.next;
    }
};