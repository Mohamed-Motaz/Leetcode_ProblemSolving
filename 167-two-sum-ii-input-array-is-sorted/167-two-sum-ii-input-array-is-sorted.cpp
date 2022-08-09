class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++){
            int s = i + 1, e = numbers.size() - 1, m;

            while (s <= e){
                m = (s + e) / 2;
                if (numbers[i] + numbers[m] < target)
                    s = m + 1;
                else if (numbers[i] + numbers[m] > target)
                    e = m - 1;
                else
                    return {i + 1, m + 1};
            }
        }
        return {};
    }
};