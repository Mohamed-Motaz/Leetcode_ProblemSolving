class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long res = 0;
        for (int i = 0; i < nums.size(); i++){
            long long sum = 0;
            unordered_set<int> s;
            for (int j = i; j < nums.size(); j++){
                s.insert(nums[j]);
                res +=  s.size() * s.size();
            }
        }
        return res;
    }
};

//1 12 121
//2 21
//1