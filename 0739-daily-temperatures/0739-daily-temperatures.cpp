class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         stack<pair<int, int>> st; //{val, idx}
        vector<int> sol(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++)
        {

            while (!st.empty() && temperatures[i] > st.top().first)
            {
                sol[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({temperatures[i], i});
        }
        return sol;
    }
};