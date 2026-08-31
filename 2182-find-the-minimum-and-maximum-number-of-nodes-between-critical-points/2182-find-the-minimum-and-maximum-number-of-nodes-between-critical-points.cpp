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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> points;

        ListNode* prev = head;
        ListNode* temp = head->next;

        int index = 1;

        while(temp->next != NULL) {

            if ((prev->val > temp->val && temp->val < temp->next->val) ||
                (prev->val < temp->val && temp->val > temp->next->val)) {

                points.push_back(index);
            }

            prev = temp;
            temp = temp->next;
            index++;
        }

        if(points.size() < 2)
            return {-1, -1};

        int minDistance = INT_MAX;
        int maxDistance = points.back() - points[0];

        for(int i = 1; i < points.size(); i++) {
            minDistance = min(minDistance, points[i] - points[i-1]);
        }

        return {minDistance, maxDistance};
    }
};