class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else if (nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while (l < nums.size() && nums[l] == nums[l - 1])
                        l++;
                    while (r >= 0 && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        
        return res; 
    }
};