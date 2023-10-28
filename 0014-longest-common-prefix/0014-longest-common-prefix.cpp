class Solution {
public:
    string sortSol(vector<string>& strs){
        sort(strs.begin(), strs.end());
        const int n = strs[0].size();
        const int m = strs.back().size();
        string ans = "";
        for (int i = 0; i < min(n, m); i++){
            if (strs[0][i] != strs.back()[i])
                return ans;
            ans += strs[0][i];
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        return sortSol(strs);
    }
};