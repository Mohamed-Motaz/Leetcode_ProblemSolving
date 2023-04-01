class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int &i : nums)
            mp[i] = 1;

        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int curNum = nums[i] - 1;
            int ctr = 1;
            while (mp[curNum] == 1)
            {
                curNum--;
                ctr++;
            }
            ctr += mp[curNum];
            mp[nums[i]] = ctr;
            mx = max(mx, ctr);
        }

        return mx;
    }
};