class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        int res = 0;
        
        for (int i = 0; i < processorTime.size(); i++){
            int start = i * 4;
            for (int j = 0; j < 4; j++){
                res = max(res, processorTime[i] + tasks[start + j]);
            }
        }
        
        return res;
    }
};