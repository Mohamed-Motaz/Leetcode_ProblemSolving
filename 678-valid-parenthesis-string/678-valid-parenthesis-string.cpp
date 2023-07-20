class Solution {
public:
    bool checkValidString(string s) {
        deque<int> st;
        queue<int> dq;
        int all = 0;
        int notClosed = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '*') {
                dq.push(i);
            }
            else if (s[i] == ')'){
                if (!st.size()){
                    if (dq.size()){
                        dq.pop();
                    }
                    else return 0;
                }else{
                    st.pop_back();
                }
            }else{
                st.push_back(i);
            }
        }
        while (st.size() && dq.size()){
            int cur = st.front();
            int help = dq.front();
            if (help > cur){
                st.pop_front();
                dq.pop();
            }else{
                dq.pop();
            }
        }
        return st.empty();
    }
};