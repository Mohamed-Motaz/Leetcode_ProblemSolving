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
        ListNode* l1Head = list1, *l2Head = list2;
        ListNode* newHead = nullptr;
        ListNode* toRet = nullptr;

        while (true){
            if (l1Head && l2Head){
                if (l1Head->val <= l2Head->val) {
                    if (!newHead)
                    {
                        newHead = new ListNode(l1Head->val);
                        toRet = newHead;
                    }
                    else {
                        newHead->next = l1Head;
                        newHead = newHead->next;
                    }
                    l1Head = l1Head->next;
                }
                else {
                    if (!newHead)
                    {
                        newHead = new ListNode(l2Head->val);
                        toRet = newHead;
                    }
                    else {
                        newHead->next = l2Head;
                        newHead = newHead->next;
                    }
                    l2Head = l2Head->next;
                }
            }else if (l1Head){
                if (!newHead)
                {
                    newHead = new ListNode(l1Head->val);
                    toRet = newHead;
                }
                else {
                    newHead->next = l1Head;
                    newHead = newHead->next;
                }
                l1Head = l1Head->next;
            }else if (l2Head){
                if (!newHead)
                {
                    newHead = new ListNode(l2Head->val);
                    toRet = newHead;
                }
                else {
                    newHead->next = l2Head;
                    newHead = newHead->next;
                }
                l2Head = l2Head->next;
            }else
                break;
        }

        return toRet;
    }
};