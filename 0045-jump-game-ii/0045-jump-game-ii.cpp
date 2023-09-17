class Solution {
public:
    vector<vector<int>> dp;
    int rows, cols;
    
    
    int jump(vector<int>& nums) {
        rows = nums.size();
        
        vector<int> v(nums.size(), INT32_MAX);
        
        v[0] = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++){
                v[j] = min(v[j], v[i] + 1);
            }
        }
        return v.back();
    }
};