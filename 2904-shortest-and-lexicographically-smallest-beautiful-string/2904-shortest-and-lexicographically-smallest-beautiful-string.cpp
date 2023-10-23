class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int ansSize = INT32_MAX;
        int start = 0, end = 0;
        int ctr = 0;
        while (end < s.size()){
            if (s[end] == '1'){
                ctr++;
            }
            while (s[start] == '0' || ctr > k){
                if (s[start] == '1') ctr--;
                start++;
            }
            if (ctr == k){
                int sz = end - start + 1;
                string tmp = s.substr(start, sz);
                if (sz < ansSize){
                    ansSize = sz;
                    ans = tmp;
                }else if (sz == ansSize){
                    if (tmp < ans){
                        ans = tmp;
                    }
                }
            }
            
            end++;
        }
        return ans;
    }
};