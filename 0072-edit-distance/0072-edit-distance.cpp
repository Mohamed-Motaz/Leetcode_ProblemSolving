class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int idx1, int idx2, string &word1, string &word2){
        int &ans = dp[idx1][idx2];
        if (ans != -1)
            return ans;
        
        if (idx1 == 0 || idx2 == 0)
            return ans = idx1 == 0 ? idx2 : idx1;
        // if (idx2 == word2.size())
        //     return abs((int)word1.size() - idx2);
        
        
        
        ans = 5000;
        
        if (word1[idx1 - 1] == word2[idx2 - 1])
            ans = min(ans, solve(idx1 - 1, idx2 - 1, word1, word2));
        else
            ans = min({
                    ans,
                    solve(idx1 - 1, idx2 - 1, word1, word2) + 1, //replace, so just assume it works
                    solve(idx1, idx2 - 1, word1, word2) + 1, //insert a new letter in word1, so idx1 remains the same, idx2 moves
                    solve(idx1 - 1, idx2, word1, word2) + 1,    //delete the letter in word1, so idx1 increases
                });
        
        
        return ans;
    }
    
    int minDistance(string word1, string word2) {
        dp.resize(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        
        return solve(word1.size(), word2.size() , word1, word2);
    }
};