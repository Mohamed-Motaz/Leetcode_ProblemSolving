class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        x = abs(x);
        long long ans = 0;
        while (x){
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        if (neg) ans *= -1;
        return ans <= INT32_MAX && ans >= INT32_MIN ? ans : 0;
    }
};
