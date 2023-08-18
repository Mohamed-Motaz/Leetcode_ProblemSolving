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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        ListNode* start = NULL;
        
        
        while (n--){
            end = end->next;
        }
        while (end != NULL){
            end = end->next;
            if (start == NULL)
                start = head;
            else
                start = start->next;
        }
        
        //remove the one after the start
        if (start == NULL)
            head = head->next;
        else
            start->next = start->next->next;
        
        
        return head;
    }
};