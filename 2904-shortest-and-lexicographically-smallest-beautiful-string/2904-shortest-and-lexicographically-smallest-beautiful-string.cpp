class Solution {
public:
    bool isSmaller(string s, string t){
        if (s.size() < t.size()) return 1;
        int i = 0;
        while (i < s.size()){
            if (s[i] > t[i]) return 0;
            if (s[i] < t[i]) return 1;
            i++;
        }
        return 0;
    }
    string shortestBeautifulSubstring(string s, int k) {
        string res = s + s;
        for (int i = 0; i < s.size(); i++){
            int ctr = 0;
            for (int j = i; j < s.size(); j++){
                if (s[j] == '1') ctr++;
                if (ctr == k){
                    string tmp = s.substr(i, j - i + 1);
                    if (tmp.size() <= res.size()) {
                        if (isSmaller(tmp, res))
                        {
                            res = tmp;
                        }
                    }
                }
            }
        }
        return res == s + s ? "" : res;
    }
};