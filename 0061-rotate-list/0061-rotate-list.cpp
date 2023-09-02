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
        
        int sz = 0;
        ListNode* tmp = head;
        
        while (tmp){
            sz++;
            tmp = tmp->next;
        }
        
        k %= sz;
        if (!k)
            return head;
        tmp = head;
        
        
        ListNode* newHead = tmp;
        for (int i = 0; ; i++){
            if (i == sz - k - 1){
                ListNode* tmptmp = tmp->next;
                tmp->next = NULL;
                newHead = tmptmp;
                break;
            }
            tmp = tmp->next;
        }
        tmp = newHead;
        while (tmp->next){
            tmp = tmp->next;
        }
        tmp->next = head;
        return newHead;
    }
};