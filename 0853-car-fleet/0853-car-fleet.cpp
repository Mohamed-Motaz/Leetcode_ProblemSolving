class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ctr = 0;
        int n = position.size();
        vector<pair<double, double>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = make_pair(position[i], speed[i]);
        sort(v.begin(), v.end());

        double mxTime = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            double curTime = (target - v[i].first) / v[i].second;
            if (curTime > mxTime)
            {
                mxTime = curTime;
                ctr++;
            }
        }
        return ctr;
    }
};