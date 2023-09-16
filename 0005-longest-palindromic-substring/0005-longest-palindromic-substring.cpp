class Solution {
public:
    
    pair<int, int> solve(int left, int right, string &s){
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            left--, right++;
        }
        return make_pair(++left, --right);
    }
    
    string longestPalindrome(string s) {
        int mx = 1;
        string res = string(1, s[0]);
        
        for (int i = 0; i < s.size(); i++){
            pair<int, int> first = solve(i, i, s);
            int firstSz = first.second - first.first + 1;
            
            pair<int, int> second = solve(i, i + 1, s);
            int secondSz = second.second - second.first + 1;

            if (firstSz > mx){
                res = s.substr(first.first, firstSz);
                mx = firstSz;
            }
            if (secondSz > mx){
                res = s.substr(second.first, secondSz);
                mx = secondSz;
            }
        }
        return res;
    }
};