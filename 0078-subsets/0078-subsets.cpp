class Solution {
public:
    
    void work(vector<vector<int>> &res, vector<int>& cur, int idx, vector<int>& nums){
        if (idx == nums.size()){
            res.push_back(cur);
            return;
        }
        
        //leave
        work(res, cur, idx + 1, nums);
        
        //take
        cur.push_back(nums[idx]);
        work(res, cur, idx + 1, nums);
        cur.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        work(res, cur, 0, nums);
        return res;
    }
};