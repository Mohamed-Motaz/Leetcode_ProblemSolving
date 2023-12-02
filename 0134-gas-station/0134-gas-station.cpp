class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int sum = 0;
        int idx = 0;
        int cur = 0;
        for (int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
            
            cur += gas[i] - cost[i];
            if (cur < 0){
                cur = 0;
                idx = i + 1;
            }
        }

        if (sum < 0)
            return -1;
        
        return idx % n;


    }
};

// g = [1,2,3,4,5]
// c = [3,4,5,1,2]
// -2 -2 -2 3 3


// 5 -10 1 10 -20 10