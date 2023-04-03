class Solution {
public:
    bool ok(vector<int> &piles, int k, int h){
        int ctr = 0;
        for (auto i: piles){
            ctr += i / k;
            ctr += (i % k) ? 1: 0;
            if (ctr > h)
                return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = 1e9 + 2, m = -1;
        int mn = INT32_MAX;
        while (s <= e){
            m = (s + e) / 2;
            if (ok(piles, m, h)){
                mn = min(mn, m);
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        return mn;
    }   
};