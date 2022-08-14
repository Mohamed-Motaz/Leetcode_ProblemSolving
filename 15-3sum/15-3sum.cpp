class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            //avoid duplicates
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k){
                int cur = nums[i] + nums[j] + nums[k];
                if (cur == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    do{ j++; } while (j != nums.size() && nums[j] == nums[j - 1]);
                do{ k--; } while (k != nums.size() - 1 && k != 0 && nums[k] == nums[k + 1]);
                
                    continue;
                }else if (cur > 0)
                    k--;
                else
                    j++;

            }
        }
        return res;
    }
};