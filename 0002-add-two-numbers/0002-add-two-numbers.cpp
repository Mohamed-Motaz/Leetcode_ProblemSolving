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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(-1);
        ListNode *res = head;
        while (l1 || l2 || carry)
        {
            int f = 0, s = 0;
            if (l1)
                f = l1->val, l1 = l1->next;
            if (l2)
                s = l2->val, l2 = l2->next;

            int sum = f + s + carry;
            head->next = new ListNode(sum % 10);
            head = head->next;
            carry = sum / 10;
        }
        return res->next;
        
    }
};