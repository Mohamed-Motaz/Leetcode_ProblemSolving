class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<bool, bool>> mp; // mark if num is visited or not
        for (int e : nums)
            mp[e] = {1, 0};

        int mx = 0;
        for (int e : nums)
        {
            int ctr = 1, num = e - 1;
            while (mp[num].first)
            {
                if (mp[num].second)
                    break;
                mp[num].second = 1;
                ctr++, num--;
            }
            num = e + 1;
            while (mp[num].first)
            {
                if (mp[num].second)
                    break;
                mp[num].second = 1;
                ctr++, num++;
            }
            mp[num].second = 1;
            mx = max(mx, ctr);
        }
        return mx;
    }
};