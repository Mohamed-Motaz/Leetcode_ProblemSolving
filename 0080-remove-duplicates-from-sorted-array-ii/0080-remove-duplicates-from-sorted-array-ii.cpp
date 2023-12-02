class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i < 2 || nums[s - 2] != nums[i]){
                nums[s] = nums[i];
                s++;
            }
        }
        return s;
    }
//     int removeDuplicates(vector<int>& nums) {
        
//         int prev = INT32_MAX;
//         int s = 0;
//         bool oops = 0;
//         for (int i = 0; i < nums.size(); i++){
//             if (nums[i] == prev){
//                 if (!oops){
//                     nums[s++] = nums[i];
//                     oops = 1;
//                 }
//             }else{
//                 nums[s++] = nums[i];
//                 oops = 0;
//             }
//             prev = nums[i];
//         }
        
//         return s;
//     }
};