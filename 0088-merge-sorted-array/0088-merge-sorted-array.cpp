class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //1 3 5 7 0 0 0 0
        //2 4 6 8
        
        //edge case
        if (!m){
            while (n--){
                nums1[n] = nums2[n];
            }
            return;
        }
        
        
        int endVec = nums1.size() - 1;
        int end1 = m - 1;
        int end2 = n - 1;
        
        while (end1 >= 0 && end2 >= 0){
            if (nums1[end1] >= nums2[end2]){
                nums1[endVec] = nums1[end1];
                endVec--;
                end1--;
            }else{
                nums1[endVec] = nums2[end2];
                endVec--;
                end2--;
            }
        }
        
        while (end2 >= 0){
            nums1[endVec] = nums2[end2];
            end2--;
            endVec--;
        }
        

    }
};