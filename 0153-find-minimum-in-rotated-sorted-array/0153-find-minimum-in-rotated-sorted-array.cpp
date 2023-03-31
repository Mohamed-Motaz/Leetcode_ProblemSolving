class Solution {
public:
    int findMin(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int m = -1;
        int mn = nums[0];
        while (s <= e)
        {
            if (nums[s] <= nums[e])
            {
                return min(mn, nums[s]);
            }
            m = (s + e) / 2;
            mn = min(mn, nums[m]);
            if (nums[s] <= nums[m])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
        return mn;
    }
};