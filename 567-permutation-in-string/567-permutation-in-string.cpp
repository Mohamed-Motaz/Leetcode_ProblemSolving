class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26, 0), t(26, 0);
        for (auto e: s1) v[e - 'a']++;

        int l = 0, r = 0;
        while (l <= r && r < s2.size()){
            t[s2[r] - 'a']++;

            if (check(v, t)) {
                if (done(v, t))
                    return true;
                else {
                    r++;
                    continue;
                }
            }
            else{
                t[s2[l] - 'a']--;
                l++; r++;
            }

        }

        return false;
    }
    
    bool check(vector<int> &v, vector<int>& t){
        for (int i = 0; i < v.size(); i++){
            if (t[i] > v[i])
                return false;
        }
        return true;
    }

    bool done(vector<int> &v, vector<int>& t){
        for (int i = 0; i < v.size(); i++){
            if (t[i] != v[i])
                return false;
        }
        return true;
    }
};