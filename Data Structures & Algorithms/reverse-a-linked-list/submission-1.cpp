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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = nullptr;
        ListNode* nexi = head;
        while(nexi){
            ListNode* prev = curr;
            curr = nexi;
            nexi = nexi->next;
            curr->next = prev;
        }
        return curr;
    }
};
