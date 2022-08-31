class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = 1e9 + 1, m = -1;
        int mn = INT32_MAX;
        while (s <= e){
            m = (s + e) / 2;
            if (ok(m, h, piles)){
                mn = min(mn, m);
                e = m - 1;
            }else{
                s = m + 1;
            }
        }
        return mn;
    }
    
    bool ok(int k, int h, vector<int>& piles){
        long long tot = 0;
        for (int i = 0; i < piles.size(); i++){
            tot += ceil(piles[i] / (double)k);
        }
        return tot <= h;
    }
};