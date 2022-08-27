class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
         deque<int> dq; //monotonic decreasing queue
         int l = 0, r = 0;

         while (r < nums.size()){
            while (dq.size() && nums[r] > nums[dq.back()])
                dq.pop_back();

            while (dq.size() && dq.front() < l)
                dq.pop_front();

            dq.push_back(r);

            if (r >= k - 1){
                res.push_back(nums[dq.front()]);
                l++;
            }
            r++;
         }
        return res;
    }
};