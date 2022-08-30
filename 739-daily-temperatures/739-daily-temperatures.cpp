class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; //value, index
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++){
            while (!st.empty() && temperatures[i] > st.top().first){
                pair<int, int> cur = st.top(); st.pop();
                res[cur.second] = i - cur.second;
            }
            st.push({temperatures[i], i});
        }

        while (!st.empty()){
            pair<int, int> cur = st.top(); st.pop();
            res[cur.second] = 0;
        }

        // for (auto e: res)
        //     cout << e << " ";
        return res;
    }
};