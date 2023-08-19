class Solution {
public:
    void solve(int idx, string &cur, string& s, vector<string> &v){
        if (idx == s.size()){
            if (cur.size()) v.push_back(cur);
            return;
        }
        
        int num = s[idx] - '0';
        int calc = (num - 2) * 3;
        if (num >= 8)
            calc++;
        
        cur += (calc + 'a');
        solve(idx + 1, cur, s, v);
        cur.pop_back();
        
        cur += (calc + 1 + 'a');
        solve(idx + 1, cur, s, v);
        cur.pop_back();
        
        cur += (calc + 2 + 'a');
        solve(idx + 1, cur, s, v);
        cur.pop_back();
        
        if (num == 7 || num == 9){
            cur += (calc + 3 + 'a');
            solve(idx + 1, cur, s, v);
            cur.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> sol;
        string s = "";
        solve(0, s, digits, sol);
        return sol;
    }
};