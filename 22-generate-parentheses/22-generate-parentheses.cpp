class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s;
        for (int i = 0; i < n; i++) s += "(";
        for (int i = 0; i < n; i++) s += ")";
        vector<string> res;
        do{
            if (ok(s))
                res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
    
    bool ok(string s){
        stack<char> st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ')'){
                if (st.empty())
                    return false;
                st.pop();
            }else
                st.push(s[i]);
        }
        return st.empty();
    }
};