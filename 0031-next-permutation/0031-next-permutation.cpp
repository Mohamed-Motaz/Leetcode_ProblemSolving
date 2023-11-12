class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int p = -1; //half point
        
        for (int i = nums.size() - 1; i >= 1; i--){
            if (nums[i] > nums[i - 1]){
                p = i;
                break;
            }
        }
        
        if (p == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        //cout << p << endl;
        
        //find the first num greater than p - 1
        for (int i = nums.size() - 1; i >= 0; i--){
            if (nums[i] > nums[p - 1]){
                swap(nums[p - 1], nums[i]);
                reverse(nums.begin() + p, nums.end());
                return;
            }
        }
        
       
    }
};

//1 2 3 --> 1 3 2

//1 2 3 4 --> 1 2 4 3
 
//1 2 3 4 1 --> 1,2,4,1,3

//1 2 3 4 1 0 --> 1,2,4,0,1,3
