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
    private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* nexi = head;
        while(nexi){
            ListNode* curr = nexi;
            nexi = nexi->next;
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        
        // reversing the second half
        ListNode* ptr1 = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ptr2 = reverse(slow->next);
        slow->next = nullptr;
        
        // solving
        ListNode* temp = new ListNode(-1);
        ListNode* tail = temp;
        while(ptr1 || ptr2){
            if(ptr1){
                tail->next = ptr1;
                tail = tail->next;
                ptr1 = ptr1->next;
                tail->next = nullptr;
            }
            if(ptr2){
                tail->next = ptr2;
                tail = tail->next;
                ptr2 = ptr2->next;
                tail->next = nullptr;
            }
        }
        head = temp->next;
    }
};
