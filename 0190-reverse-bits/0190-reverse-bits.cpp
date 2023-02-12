class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int p = 32;
        while (n){
            int val = n % 2;
            n /= 2;
            p--;
            if (!val){
                continue;
            }
            ans += pow(2, p);
        }
        return ans;
    }
};