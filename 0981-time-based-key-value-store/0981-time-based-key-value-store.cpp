class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp[key].empty())
            return "";

        pair<int, string> p = make_pair(timestamp, "");
        int idx = lower_bound(mp[key].begin(), mp[key].end(), p) - mp[key].begin();

        if (idx == mp[key].size())
        {
            return mp[key].back().second;
        }

        if (mp[key][idx].first == timestamp)
        {
            return mp[key][idx].second;
        }

        if (idx){
            return mp[key][--idx].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */