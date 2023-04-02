class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int mx = 0;

        while (l < r)
        {

            mx = max((r - l) * min(height[l], height[r]), mx);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return mx;
    }
};