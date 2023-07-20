class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open, star;
        
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                open.push(i);
            }else if (s[i] == ')'){
                if (open.size())
                    open.pop();
                else if (star.size()){
                    star.pop();
                }else{
                    return false;
                }
            }else{
                star.push(i);
            }
        }
        
        while (!open.empty() && !star.empty()){
            int cur = star.top();
            if (cur < open.top()){
                star.pop();
                continue;
            }
            star.pop();
            open.pop();
        }
        return open.empty();
    }
};