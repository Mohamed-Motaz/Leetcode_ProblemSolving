class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        int s, e, m;
        for (int i = 0; i < n - 1; i++){
            s = i + 1, e = n - 1, m = -1;
            int needed = target - numbers[i];
            while (s <= e){
                m = (s + e) / 2;
                if (numbers[m] > needed)
                    e = m - 1;
                else if (numbers[m] < needed)
                    s = m + 1;
                else
                    return {i + 1, m + 1};
            }
        }
        return {};
    }
};