class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st; //index, value
        vector<int> res(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++){

            while (!st.empty() && temperatures[i] > st.top().second){
                pair<int, int> p = st.top();
                st.pop();
                res[p.first] = i - p.first;
            }
            st.push({i, temperatures[i]});
        }
        return res;
    }
};