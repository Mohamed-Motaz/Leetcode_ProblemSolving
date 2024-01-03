class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0;
        
        int prevCtr = 0;
        for (int i = bank.size() - 1; i >= 0; i--){
            int myCtr = 0;
            for (int j = 0; j < bank[i].size(); j++){
                if (bank[i][j] == '1')
                    myCtr++;
            }
            res += myCtr * prevCtr;
            
            if (myCtr)
                prevCtr = myCtr;
        }
        return res;
    }
};