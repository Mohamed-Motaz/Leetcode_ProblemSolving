class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (1){
            int sum = 0;
            while (n){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1) return 1;
            if (st.find(sum) != st.end()) return 0;
            n = sum;
            st.insert(n);
        }
        return 0;
    }
};