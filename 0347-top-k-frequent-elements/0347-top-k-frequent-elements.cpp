class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ctr;
        for (int &e: nums){
            ctr[e]++;
        }

        vector<vector<int>> v(nums.size() + 1);
        for (auto e: ctr){
            v[e.second].push_back(e.first);
        }

        vector<int> sol;
        for (int i = v.size() - 1; i >= 0 && k; i--){
            if (v[i].size())
                for (int j = 0; j < v[i].size() && k; j++)
                    sol.push_back(v[i][j]), k--;
        }

        return sol;
    }
};