class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int m = -1;

        while (s <= e)
        {
            m = (s + e) / 2;
            if (nums[m] == target)
                return m;
            if (nums[s] <= nums[m])
            {
                // left is sorted
                if (target >= nums[s] && target <= nums[m])
                    e = m - 1;
                else
                    s = m + 1;
            }
            else
            {
                // right is sorted
                if (target >= nums[m] && target <= nums[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return -1;
    }
};