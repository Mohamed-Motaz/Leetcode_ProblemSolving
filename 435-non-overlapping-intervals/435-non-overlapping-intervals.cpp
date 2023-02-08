class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ctr = 0;
        pair<int, int> prev = make_pair(intervals[0][0], intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prev.second)
            {
                // remove the one with the longer end

                if (prev.second > intervals[i][1])
                {
                    prev.first = intervals[i][0];
                    prev.second = intervals[i][1];
                }

                ctr++;
            }
            else
            {
                prev.first = intervals[i][0];
                prev.second = intervals[i][1];
            }
        }
        return ctr;
    }
};