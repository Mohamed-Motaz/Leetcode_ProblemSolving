class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mx = INT32_MIN;

        for (int e: nums){
            mx = max(mx, e);
            sum += e;
            mx = max(mx, sum);
            if (sum < 0)
                sum = 0;
        }

        return max(mx, sum == 0 ? INT32_MIN : sum);

    }
};