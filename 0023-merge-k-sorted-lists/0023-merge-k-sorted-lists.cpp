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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(INT32_MIN);
        ListNode* copy = head;
        unordered_set<ListNode*> lst;
        for (auto e: lists){
            if (e) lst.insert(e);
        }
        while (lst.size()){
            ListNode* mn = new ListNode(INT32_MAX);
            
            for (auto it: lst){
                if (!it){
                    continue;
                }
                if (it->val < mn->val){
                    mn = it;
                }
            }
            auto next = mn->next;
            lst.erase(lst.find(mn));

            if (next){
                lst.insert(next);
            }
            
            
            head->next = mn;
            head->next->next = NULL;
            head = head->next;
        }
        
        return copy->next;
    }
};