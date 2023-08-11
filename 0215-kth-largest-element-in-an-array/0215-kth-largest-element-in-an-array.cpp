class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(0, nums.size() - 1, k, nums);
    }
    
    int quickSelect(int s, int e, int k, vector<int> &nums){
        if (e < s)
            return 0;
        
        int pivot = partition(s, e, nums);
        
        if (pivot < k) return quickSelect(pivot + 1, e, k, nums); //check the right
        if (pivot > k) return quickSelect(s, pivot - 1, k, nums); //check the left
        return nums[pivot]; //found it!

    }
    
    int partition(int s, int e, vector<int> &nums){
        int pivot = nums[e];
        int left = s;
        
        for (int i = s; i <= e - 1; i++){
            if (nums[i] <= pivot){
                swap(nums[i], nums[left++]);
            }
        }
        
        swap(nums[e], nums[left]);
        return left;
    }
};