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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        
        int sz = 1;
        ListNode* tmp = head;
        
        while (tmp->next){
            sz++;
            tmp = tmp->next;
        }
        //circle the linked list
        tmp->next = head;

        
        k %= sz;

        for (int i = 0; i < sz - k; i ++){
            tmp = tmp->next;
        }
        
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};