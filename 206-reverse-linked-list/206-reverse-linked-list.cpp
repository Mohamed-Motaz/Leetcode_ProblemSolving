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
        if (head == nullptr)
            return nullptr;
        ListNode* prev = head;
        head = head->next;
        int ctr = 0;
        while (true){
            if (head == nullptr)
                return prev;
            ctr++;
            if (ctr == 1){
                //first iteration
                prev->next = nullptr;
            }
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return nullptr;
    }
};