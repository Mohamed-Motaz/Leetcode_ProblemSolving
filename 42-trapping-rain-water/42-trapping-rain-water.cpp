class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    int i = 0, j = n - 1;
    int mxLeft = height[i], mxRight = height[j];
    int res = 0;
    while (i < j){
        if (mxLeft <= mxRight){
            res += mxLeft - height[i];
            i++;
            mxLeft = max(mxLeft, height[i]);
        }else{
            res += mxRight - height[j];
            j--;
            mxRight = max(mxRight, height[j]);
        }
    }
        return res;
    }
};