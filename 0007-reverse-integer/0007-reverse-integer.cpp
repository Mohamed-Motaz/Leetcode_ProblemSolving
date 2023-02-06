class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        x = abs(x);
        long long ans = 0;

        while (x)
        {
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        neg ? ans *= -1 : ans;
        return (ans > INT32_MAX || ans < INT32_MIN) ? 0 : ans;
    }
};