class Solution {
public:
    int ok(int num){
        string s = to_string(num);
        if (s.size() % 2) return 0;
        
        int ctr = 0;
        for (int i = 0; i < s.size() / 2; i++) ctr += (s[i] - '0');
        for (int i = s.size() / 2; i < s.size(); i++) ctr -= (s[i] - '0');
        return !ctr;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++){
            cnt += ok(i);
        }      
        return cnt;
    }
};