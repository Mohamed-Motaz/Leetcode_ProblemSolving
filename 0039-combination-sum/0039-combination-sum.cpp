class Solution {
public:
        void work(vector<vector<int>> &sol, vector<int> &candidates, int target, int idx, int curValue, vector<int> &curVec)
    {
        if (curValue > target)
        {
            return;
        }

        if (curValue == target)
        {
            sol.push_back(curVec);
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            curVec.push_back(candidates[i]);
            work(sol, candidates, target, i, curValue + candidates[i], curVec);
            curVec.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> sol;
        vector<int> curVec;
        work(sol, candidates, target, 0, 0, curVec);
        return sol;
    }
};