class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int ans = 0;
        
        for (int num: nums){
            cnt[num]++;
        }
        
        for (auto [_, c]: cnt){
            if (c == 1)
                return -1;
            if (c % 3 == 0){
                ans += c / 3;
            }else if (c % 3 == 1){ //4, or 7
                ans += c / 3 + 1;
            }else if (c % 3 == 2){ //5 or 8
                ans += c / 3 + 1;                
            }
        }
        
        return ans;
    }
};