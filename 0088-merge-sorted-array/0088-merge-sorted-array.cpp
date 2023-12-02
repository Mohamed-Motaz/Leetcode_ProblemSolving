class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //1 3 5 7 0 0 0 0
        //2 4 6 8
        
        
        //nums2 should be merged into nums1
        int end1 = m - 1;
        int end2 = n - 1;
        int endVec = n + m - 1;
        
        while (end2 >= 0){
            if (end1 >= 0 && nums1[end1] >= nums2[end2]){
                nums1[endVec] = nums1[end1];
                end1--;
                endVec--;
            }else{
                nums1[endVec] = nums2[end2];
                end2--;
                endVec--;
            }
        }

    }
};