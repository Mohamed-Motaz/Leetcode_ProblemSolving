/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> st;
    Node* solveRecursion(Node* head){   
        if (head == NULL) return NULL;

        if (st.find(head) != st.end()){
            return st[head];
        }
        
        Node* copy = new Node(head->val);
        st[head] = copy;
        
        copy->next = solveRecursion(head->next);
        copy->random = solveRecursion(head->random);
        
        

        return st[head];
    }
    
    Node* copyRandomList(Node* head) {
        return solveRecursion(head);
    }
};