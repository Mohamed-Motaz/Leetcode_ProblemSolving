class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(int idx, int cur,  vector<int>& sol, int target, vector<int>& candidates){
        
        if (cur == target) {
            res.push_back(sol);
            return;
        }
        if (cur > target){
            return;
        }

       
        for (int i = idx; i < candidates.size(); i++){
            if (i > idx){ //bug that i always forget
                if (candidates[i] == candidates[i - 1]) continue;
            }
            sol.push_back(candidates[i]);
            solve(i + 1, cur + candidates[i], sol, target, candidates);
            sol.pop_back();
        }
        
         
        return;
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //my bug was that i forgot to sort to eliminate duplicates
        vector<int> sol;
        solve(0, 0, sol, target, candidates);   
        return res;
    }
};