class Solution {
public:
    
    bool isPali(string s){
        for (int i = 0; i < s.size() / 2; i++){
            if (s[i] != s[s.size() - i - 1]) return 0;
        }
        return 1;
    }
    
    vector<vector<string>> sol;

    void solve(int curIdx, string cur, string &s, vector<string>& tmpSol){
        if (curIdx == s.size()){
            if (cur == "")
                sol.push_back(tmpSol);
            return;
        }
        
        if (isPali(cur + s[curIdx])){
            //can start over
            tmpSol.push_back(cur + s[curIdx]);
            solve(curIdx + 1, "", s, tmpSol);
            tmpSol.pop_back();
        }
        //continue normally
        solve(curIdx + 1, cur + s[curIdx], s, tmpSol);
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string> tmpSol;
        
        solve(0, "", s, tmpSol);
        
        return sol;
    }
};