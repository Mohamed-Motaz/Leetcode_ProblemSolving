class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        k %= nums.size();
        
        int s = 0;
        for (int i = nums.size() - k; i < nums.size(); i++){
            tmp[s++] = nums[i];
        }
        
        
        for (int i = 0; i + k < nums.size(); i++){
            tmp[i + k] = nums[i];
        }
        
        
        nums = tmp;
    }
};