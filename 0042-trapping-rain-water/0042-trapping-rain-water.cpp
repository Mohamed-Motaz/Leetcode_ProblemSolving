class Solution {
public:
    int trap(vector<int>& height) {
        int tot = 0;
        vector<int> mxRight(height.size());
        mxRight[height.size() - 1] = height[height.size() - 1];
        
        for (int i = height.size() - 2; i >= 0; i--)
            mxRight[i] = max(height[i], mxRight[i + 1]);
        
        int mxLeft = height[0];
        for (int i = 1; i < height.size() - 1; i++){
            mxLeft = max(mxLeft, height[i]);
            tot += max(0, min(mxRight[i], mxLeft) - height[i]);
        }
        
        
        return tot;
    }
};