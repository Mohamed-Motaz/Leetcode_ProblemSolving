class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        string ret = "";
        vector<pair<int, string>> &v = mp[key];

        int s = 0, e = v.size() - 1, m = -1;
        while (s <= e){
            m = (s + e) / 2;
            if (v[m].first == timestamp){
                ret = v[m].second;
                break;
            }
            else if (v[m].first < timestamp){
                ret = v[m].second;
                s = m + 1;
            }else
                e = m - 1;
        }
        return ret;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */