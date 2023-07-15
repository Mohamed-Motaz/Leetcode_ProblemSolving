class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool f = 0, s = 0, t = 0;
        for (int i = 0; i < triplets.size(); i++)
        {
            if (triplets[i][0] > target[0] ||
                triplets[i][1] > target[1] ||
                triplets[i][2] > target[2])
                continue;

            if (triplets[i][0] == target[0])
                f = 1;
            if (triplets[i][1] == target[1])
                s = 1;
            if (triplets[i][2] == target[2])
                t = 1;
        }

        return f && s && t;
    }
};