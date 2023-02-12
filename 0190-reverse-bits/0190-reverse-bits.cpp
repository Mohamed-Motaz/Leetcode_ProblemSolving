class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int p = 32;
        while (n){
            int val = n & 1;
            n >>= 1;
            p--;
            if (!val){
                continue;
            }
            ans |= 1 << p;
        }
        return ans;
    }
};