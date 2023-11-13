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
    void stackSol(ListNode* head){
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
    void reorderList(ListNode* head) {
        //stackSol(head);
        reverseAndMerge(head);
    }
    
    void reverseAndMerge(ListNode* head){
        //1 2 3 4 5
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* nextHalf = slow->next;
        slow->next = NULL;
        

        
        ListNode* l1 = head;
        ListNode* l2 = reverse(nextHalf);

        // while (l2){
        //     cout << l2->val << " ";
        //     l2 = l2->next;
        // }
        // cout << endl;
     

        merge(l1, l2);
    }
    
    ListNode* reverse(ListNode* head) {
        //123
        ListNode* prev = NULL;

        while (head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    //1 2 3     4 5
    void merge(ListNode* l1, ListNode* l2){
       
        while (l2){
            ListNode* first = l1->next;
            ListNode* second = l2->next;
            
            l1->next = l2;
            l2->next = first;
            
            l1 = first;
            l2 = second;
        }
        
    }
    
    
};

// [1,2,3,4,5]
// [1,5,2,3,4]