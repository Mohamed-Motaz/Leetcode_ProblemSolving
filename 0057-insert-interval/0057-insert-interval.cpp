class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int s = newInterval[0];
        int e = newInterval[1];

        for (int i = 0; i < intervals.size(); i++)
        {
            // 3 cases

            if (e < intervals[i][0])
            {
                // newInterval after curInterval
                res.push_back({s, e});
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                return res;
            }
            else if (s > intervals[i][1])
            {
                // newInterval before curInterval
                res.push_back(intervals[i]);
            }
            else
            {
                // newInterval overlaps, so only chage bounds
                s = min(s, intervals[i][0]);
                e = max(e, intervals[i][1]);
            }
        }
        res.push_back({s, e});
        return res;
    }
};