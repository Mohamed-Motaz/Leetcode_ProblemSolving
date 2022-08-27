class Solution {
public:
    string minWindow(string s, string t) {
        deque<char> res, tmp;
        unordered_map<char, int> m1, m2;
        for (auto e: t) m2[e]++;
        int need = m2.size(), have = 0;
        int l = 0, r = 0;

        while (r < s.size()){
            char cur = s[r];
            m1[cur]++;
            tmp.push_back(cur);
            if (m1[cur] == m2[cur])
                have++;

            while (need == have){
                if (res.empty())
                    res = tmp;
                else if (tmp.size() < res.size())
                    res = tmp;
                char remove = s[l];
                if (m1[remove] == m2[remove])
                    have--;
                tmp.pop_front();
                m1[remove]--;
                l++;
            }
            r++;
        }
        string ans = "";
        while (res.size()) ans += res.front(), res.pop_front();
        return ans;
    }
};