class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;
        
        vector<int> v(26, 0);
        
        for (int i = 0; i < m; i++){
            v[s1[i] - 'a']--;
            v[s2[i] - 'a']++;
        }
        
        if (isPermu(v))
            return true;

        for (int i = m; i < n; i++){
            v[s2[i] - 'a']++;
            v[s2[i - m] - 'a']--;
            if (isPermu(v))
                return true;
        }

        return false;
    }
    
    bool isPermu(vector<int>& v){
        for (auto e: v)
            if (e != 0)
                return false;
        return true;
    }

};