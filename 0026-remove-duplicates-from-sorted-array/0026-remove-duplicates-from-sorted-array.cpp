class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prevIdx = 0;
        int prevNum = -200;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != prevNum){
                prevNum = nums[i];
                nums[prevIdx++] = nums[i];
            }
        }
        return prevIdx;
    }
};