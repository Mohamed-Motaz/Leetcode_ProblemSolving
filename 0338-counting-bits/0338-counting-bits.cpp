class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0, 1, 1, 2, 1, 2, 2, 3};
        if (n <= 7)
        {
            while (n + 1< res.size() )
            {
                res.pop_back();
            }
            return res;
        }

        int left = 4; // copy index
        int ctr = left;
        int sz = 8;
        int addOne = 0;

        n -= 7;

        while (n)
        {
            n--;
            res.push_back(res[ctr++] + addOne);
            if (ctr == sz / 2 + left)
            {
                // reached half
                addOne = 1;
            }
            else if (ctr == sz + left)
            {
                // reached the end
                left += sz / 2;
                ctr = left;
                sz *= 2;
                addOne = 0;
            }
        }

        return res;
    }
};