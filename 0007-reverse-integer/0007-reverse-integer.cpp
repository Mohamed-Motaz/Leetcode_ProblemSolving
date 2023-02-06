class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if (x < 0)
            neg = true;

        x = abs(x);
        string s = to_string(x);

        long long tmp = 0;
        long long times = 1;
        for (int j = 0; j < s.size(); j++)
        {
            tmp += (s[j] - '0') * times;
            times *= 10;
        }
        neg ? tmp *= -1 : tmp;
        if (tmp > INT32_MAX || tmp < INT32_MIN)
            return 0;
        return tmp;
    }
};