class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int half = total / 2;

        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        //always make sure nums1 is less than nums2
        int l = 0, r = nums1.size() - 1;
        
        while (true){
            int m = floor((l + r) / 2.0);
            int j = half - m - 2;
            
            int nums1Left = m >= 0 ? nums1[m] : INT32_MIN;
            int nums1Right = m + 1 < nums1.size() ? nums1[m + 1] : INT32_MAX;
            int nums2Left = j >= 0 ? nums2[j] : INT32_MIN;
            int nums2Right = j + 1 < nums2.size() ? nums2[j + 1] : INT32_MAX;

            if (nums1Left <= nums2Right && nums2Left <= nums1Right){
                if (total % 2)
                    return min(nums1Right, nums2Right);
                else
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right) ) / 2.0;
            }else{
                if (nums1Left > nums2Right)
                    r = m - 1;
                else if (nums2Left > nums1Right)
                    l = m + 1;
      
            }
        }
        return 0;
    }
};


