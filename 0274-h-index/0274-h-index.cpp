class Solution {
public:
    
    bool ok(int m, vector<int>& citations){
        int ctr = 0;
        for (auto e: citations){
            if (e >= m)
                ctr++;
        }
        return ctr >= m;
    }
    
    int hIndex(vector<int>& citations) {
        
        int s = 0, e = citations.size();
        int m = -1;
        int res = 0;
        while (s <= e){
            m = (s + e) / 2;
            if (ok(m, citations)){
                res = max(res, m);
                s = m + 1;
            }else
                e = m - 1;
        }
        
        return res;
    }
};