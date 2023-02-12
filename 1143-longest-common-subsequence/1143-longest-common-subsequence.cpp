int dp[1001][1001];
int work(int i1, int i2, string &text1, string &text2)
{
    if (i1 == text1.size() || i2 == text2.size())
        return 0;
    int &ans = dp[i1][i2];
    if (ans != -1)
        return ans;

    ans = 0;

    if (text1[i1] == text2[i2])
    {
        ans += max({work(i1 + 1, i2 + 1, text1, text2) + 1, //take
                    work(i1 + 1, i2, text1, text2), //leave
                    work(i1, i2 + 1, text1, text2)}); //leave
    }
    else
    {
        ans += max(work(i1 + 1, i2, text1, text2), work(i1, i2 + 1, text1, text2));
    }
    return ans;
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        return work(0, 0, text1, text2);
    }
};