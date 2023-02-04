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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *cur = new ListNode(INT32_MAX);
        ListNode *res = cur;

        while (list1 || list2)
        {
            cur->next = new ListNode();
            cur = cur->next;

            int f = list1 ? list1->val : INT32_MAX;
            int s = list2 ? list2->val : INT32_MAX;

            if (f < s)
            {
                cur->val = f;
                list1 = list1->next;
            }
            else
            {
                cur->val = s;
                list2 = list2->next;
            }
        }

        return res->next;
    }
};