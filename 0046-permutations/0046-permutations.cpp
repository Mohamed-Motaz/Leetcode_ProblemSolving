class Solution {
public:
    
    unordered_set<int> taken;
    vector<vector<int>> sol;
    void solve(int cnt, vector<int>& res, vector<int> &nums){
        if (cnt == nums.size()){
            sol.push_back(res);
            return;
        }
        
        for (auto i: nums){
            if (taken.find(i) != taken.end()) continue;
            
            taken.insert(i);
            res.push_back(i);
            solve(cnt + 1, res, nums);
            res.pop_back();
            taken.erase(i);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> res;
        solve(0, res, nums);
        return sol;
    }
};