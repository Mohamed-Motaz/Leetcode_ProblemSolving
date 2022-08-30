class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto e: s){
            if (e == ')' || e == ']' || e == '}'){
                if (st.empty())
                    return false;
                if (e == ')' && st.top() != '(')
                    return false;
                if (e == '}' && st.top() != '{')
                    return false;
                if (e == ']' && st.top() != '[')
                    return false;
                st.pop();
            }else{ //open
                st.push(e);
            }
        }
        return st.size() == 0;
    }
};