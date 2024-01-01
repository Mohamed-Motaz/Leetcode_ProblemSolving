class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> cur = {0, 0};
        set<pair<int, int>> s;
        map<char, pair<int,int>> mp;
        mp['N'] = {1, 0};
        mp['S'] = {-1, 0};
        mp['E'] = {0, 1};
        mp['W'] = {0, -1};
        
        s.insert(cur);
        for (char c: path){
            pair<int, int> res = mp[c];
            cur.first += res.first;
            cur.second += res.second;
            if (s.find(cur) != s.end())
                return 1;
            s.insert(cur);
        }
        return 0;
    }
};