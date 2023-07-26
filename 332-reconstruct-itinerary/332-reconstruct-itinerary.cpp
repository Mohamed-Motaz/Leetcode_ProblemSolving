class Solution {
public:
    bool solve(string cur, string par, unordered_map<string, multiset<string>> &mp, vector<string> &sol)
    {
        if (mp.empty())
            return 1;

        if (mp.size() > 1 && (mp.find(cur) == mp.end() || mp[cur].size() == 0))
        {
            // there are other nodes which I can't reach
            return 0;
        }

        multiset<string> msCopy = mp[cur];
        for (auto it = msCopy.begin(); it != msCopy.end(); ++it)
        {

            // let him try to get his child
            mp[cur].erase(mp[cur].find(*it));
            if (mp[cur].size() == 0)
                mp.erase(cur);

            sol.push_back(*it);
            bool done = solve(*it, cur, mp, sol);
            if (done)
                return 1;
            mp[cur].insert(*it);
            sol.pop_back();
        }
        return 0;
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> mp;
        for (vector<string> &v : tickets)
        {
            mp[v[0]].insert(v[1]);
        }
        vector<string> sol = {"JFK"};
        solve("JFK", "", mp, sol);
        return sol;
    }
};