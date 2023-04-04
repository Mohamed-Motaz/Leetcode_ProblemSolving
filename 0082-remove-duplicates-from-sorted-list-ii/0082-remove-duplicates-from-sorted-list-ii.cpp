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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        ListNode* prev = nullptr;
        ListNode* copy = head;
        
        
        while (head){
            if (head->next && head->next->val == head->val){
                while (head->next && head->next->val == head->val){
                    head->next = head->next->next;
                }
                if (prev) prev->next = head->next;
                else copy = head->next; //the first element was duplicated
                head = head->next;
            }else{
                prev = head;
                head = head->next;
            }
        }
        
        return copy;
    }
};