class Solution {
public:
    string minWindow(string s, string t) {
        int mnLen = INT32_MAX;
    int start = -1;
    unordered_map<char, int> m1, m2;
    for (auto e: t) m2[e]++;
    int need = m2.size(), have = 0;
    int l = 0, r = 0;

    while (r < s.size()){
        char cur = s[r];
        m1[cur]++;
        if (m1[cur] == m2[cur])
            have++;

        while (need == have){
            if  (r - l + 1 < mnLen){
                mnLen = r - l + 1;
                start = l;
            }

            char remove = s[l];
            if (m1[remove] == m2[remove])
                have--;
            m1[remove]--;
            l++;
        }
        r++;
    }
    if (start == -1)
        return "";
    else
        return s.substr(start, mnLen);
    }
};