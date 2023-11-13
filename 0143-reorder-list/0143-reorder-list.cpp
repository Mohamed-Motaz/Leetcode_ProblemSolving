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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* copy = head;
        while (copy){
            st.push(copy);
            copy = copy->next;
        }
        
        int cnt = (st.size() - 1) / 2;
        int sz = st.size();
        
        copy = head;

        while (cnt){
            ListNode* next = copy->next;
            ListNode* last = st.top();
            st.pop();

            copy->next = last;
            last->next = next;

            copy = next;

            cnt--;
        }

        st.top()->next = NULL; //to prevent infinite loop
        
        // while (head){
        //     cout << head->val << " ";
        //     head = head->next;
        // }
    }
};

// [1,2,3,4,5]
// [1,5,2,3,4]