class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int s = i + 1, e = numbers.size() - 1, m = -1;
            int t = target - numbers[i];

            while (s <= e){
                m = (s + e) / 2;
                if (numbers[m] == t)
                    return {i + 1, m + 1};

                if (numbers[m] < t)
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return {};
    }
};