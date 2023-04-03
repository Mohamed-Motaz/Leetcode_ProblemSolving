class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
        vector<vector<int>> sol = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> last = sol.back();
            if (intervals[i][0] <= last[1])
            {
                last[1] = max(last[1], intervals[i][1]);
                sol[sol.size() - 1] = last;
            }
            else
            {
                sol.push_back(intervals[i]);
            }
        }
        return sol;
    }
};