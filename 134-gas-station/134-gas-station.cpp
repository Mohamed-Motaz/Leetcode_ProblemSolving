class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0, tot = 0;        
        int res = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            cur += gas[i] - cost[i];
            tot += gas[i] - cost[i];
            
            if (cur < 0){
                cur = 0;
                res = i + 1;
            }
        }
        return tot >= 0 ? res : -1;
    }
};


