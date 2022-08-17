class Solution {
public:
    int trap(vector<int>& height) {
        int mxLeft = height[0];
        int mxRight = height.back();

        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r){
            if (mxLeft <= mxRight){
                //move to the right
                l++;
                mxLeft = max(mxLeft, height[l]);
                res += mxLeft - height[l];
            }else{
                r--;
                mxRight = max(mxRight, height[r]);
                res += mxRight - height[r];
            }
        }
        return res;
    }
};