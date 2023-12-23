class Solution {
public:
    
    bool s(vector<int>& v){
        
        for (int i = 1; i < v.size(); i++){
            if (v[i] <= v[i - 1])
                return 0;
        }
        return 1;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        vector<int> v = nums;
        int ctr = 0;
        
        for (int i = 0; i < nums.size(); i++){
            v = nums;
            for (int j = i; j < nums.size(); j++){
                v.erase(v.begin() + i);
                if (s(v)){
                    ctr++;
                }
            }
        }
        
        return ctr;
    }
};