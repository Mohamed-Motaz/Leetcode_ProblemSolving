class Solution {
public:
    
    void work(vector<vector<int>> &res, vector<int>& cur, int idx, vector<int>& nums){
        res.push_back(cur);
        
        for (int i = idx; i < nums.size(); i++){
            cur.push_back(nums[i]);
            work(res, cur, i + 1, nums);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        work(res, cur, 0, nums);
        return res;
    }
};