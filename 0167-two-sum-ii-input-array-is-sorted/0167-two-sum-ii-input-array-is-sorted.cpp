class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r){
            int cur = numbers[l] + numbers[r];
            if (cur == target)
                return {++l , ++r};
            if (cur > target)
                r--;
            else if (cur < target)
                l++;
        }
        return {};
    }
};