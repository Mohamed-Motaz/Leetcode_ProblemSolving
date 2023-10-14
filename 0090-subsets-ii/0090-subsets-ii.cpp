class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<int> cur;
        dfs(0, nums, cur, sol);
        return sol;
    }
    void dfs(int idx, vector<int>& nums, vector<int> &cur, vector<vector<int>>& sol){
        if (idx >= nums.size()){
            sol.push_back(cur);
            return;
        }
        
        
        cur.push_back(nums[idx]);
        dfs(idx + 1, nums, cur, sol);
        cur.pop_back();
        
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]){
            idx++;
        }
        dfs(idx + 1, nums, cur, sol);
    }
};