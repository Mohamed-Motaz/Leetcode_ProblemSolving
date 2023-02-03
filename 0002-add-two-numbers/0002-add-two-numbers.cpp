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
        vector<int> v1, v2;
        while (l1 != nullptr)
            v1.push_back(l1->val), l1 = l1->next;
        while (l2 != nullptr)
            v2.push_back(l2->val), l2 = l2->next;

        if (v1.size() > v2.size())
            swap(v1, v2);

        int carry = 0;

        vector<int> res;
        for (int i = 0; i < v1.size(); i++)
        {
            int sum = v1[i] + v2[i] + carry;
            res.push_back(sum % 10);
            sum /= 10;
            carry = sum;
        }

        for (int i = v1.size(); i < v2.size(); i++)
        {
            int sum = carry + v2[i];
            res.push_back(sum % 10);
            sum /= 10;
            carry = sum;
        }
        if (carry)
            res.push_back(carry);

        ListNode *dummy = new ListNode(-1);
        ListNode *copy = dummy;

        for (int i = 0; i < res.size(); i++)
        {
            dummy->next = new ListNode(res[i]);
            dummy = dummy->next;
        }
        return copy->next;
        
    }
};