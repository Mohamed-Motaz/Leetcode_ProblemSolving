class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> v(position.size());
        for (int i = 0; i < position.size(); i++) 
            v[i] = make_pair(position[i], (target - position[i]) / (double)speed[i]);

        sort(v.begin(), v.end());

        int ctr = 0;
        double mxTime = 0;
        for (int i = v.size() - 1; i >= 0; i--){
            if (v[i].second > mxTime){
                ctr++;
            }
            mxTime = max(mxTime, v[i].second);
        }

        return ctr;
    }
};


// s = d / t   t = d / s