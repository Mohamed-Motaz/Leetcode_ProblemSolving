class Solution {
public:
    double pow2(double val)
    {
        return val * val;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<double, pair<int, int>>> dist;

    for (int i = 0; i < points.size(); i++)
    {
        dist.insert(make_pair(pow2(points[i][0]) + pow2(points[i][1]),
                              make_pair(points[i][0], points[i][1])));
    }

    vector<vector<int>> res;
    auto it = dist.begin();
    while (k--){
        res.push_back({it->second.first, it->second.second});
        it++;
    }
    return res;
    }
};