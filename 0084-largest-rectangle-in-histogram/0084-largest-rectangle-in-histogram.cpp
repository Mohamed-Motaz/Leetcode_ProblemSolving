class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // index, height
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            if (st.empty())
            {
                st.push({i, heights[i]});
                continue;
            }

            if (heights[i] > st.top().second)
            {
                st.push({i, heights[i]});
                continue;
            }
            int mnIdx = heights.size();
            while (!st.empty() && heights[i] < st.top().second)
            {
                pair<int, int> prev = st.top();
                st.pop();
                ans = max(ans, (i - prev.first) * prev.second);
                mnIdx = min(mnIdx, prev.first);
            }
            st.push({mnIdx, heights[i]});
        }

        while (!st.empty())
        {
            pair<int, int> prev = st.top();
            st.pop();
            ans = max(ans, ((int)heights.size() - prev.first) * prev.second);
        }

        return ans;
    }
};