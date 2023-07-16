/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        const int RANDOM_NUM = 1e6;
        while (head){
            if (head->val == RANDOM_NUM) return true;       
            head->val = RANDOM_NUM;
            head = head->next;   
        }
        return false;
    }
};