class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = 5001;
        int s = 0, e = nums.size() - 1 , m = -1;

        while (s <= e){
            m = (s + e) / 2;
            mn = min(mn, nums[m]);

            if (nums[m] <= nums[e]){
                //this section is sorted so safe to go back
                e = m - 1;
            }else
                s = m + 1;
        }

        return mn;
    }
};