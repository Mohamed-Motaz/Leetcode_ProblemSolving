class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        string res = s + s;
        for (int i = 0; i < s.size(); i++){
            int ctr = 0;
            for (int j = i; j < s.size(); j++){
                if (s[j] == '1') ctr++;
                if (ctr == k){
                    string tmp = s.substr(i, j - i + 1);
                    if (tmp.size() < res.size()) {
                       res = tmp;
                    }else if (tmp.size() == res.size() && tmp < res)
                        res = tmp;
                }
            }
        }
        return res == s + s ? "" : res;
    }
};