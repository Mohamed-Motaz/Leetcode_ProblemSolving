class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (!n) return tasks.size();
        int mx = 0;
        vector<int> frq(26);
        for (char c : tasks)
            frq[c - 'A']++, mx = max(mx, frq[c - 'A']);

        int ctrEq = 0;
        for (int i : frq)
            if (i == mx)
                ctrEq++;

        int res = mx + (mx - 1) * n; // A B - A B - A
        res += ctrEq - 1;
        return max(res, (int)tasks.size());
    }
};