class Solution {
public:
    int mod(int x, int k){
        return ((x % k) + k) % k;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int curSum = 0;
        int sol = 0;
        unordered_map<int, int> mp;
        for (int i: nums){
            curSum += i;
            mp[mod(curSum, k)]++;
        }
        for (int i = 0; i < k; i++){
            if (!i) sol += mp[i];
            sol += mp[i] * (mp[i] - 1) / 2;
        }
        return sol;
    }
};

//nums = [4,5,0,-2,-3,1], k = 5
//4         //4(1)
//9         //4(2)    
//9         //4(3)    
//7         //2(1) 4(3)    
//4         //2(1) 4(4)!
//5         //2(1) 4(4) 0(1)
//(n)(n - 1) / 2;