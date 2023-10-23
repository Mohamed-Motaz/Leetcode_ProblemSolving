class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        
        int i = 0;
        vector<int> res;
        while (i < nums.size()){
            while (dq.size() && i - dq.front() > k - 1){
                dq.pop_front();
            }
            while (dq.size() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1)res.push_back(nums[dq.front()]);
            i++;
        }
        return res;
    }
};