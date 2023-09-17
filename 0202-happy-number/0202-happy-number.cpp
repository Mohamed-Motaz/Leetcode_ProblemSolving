class Solution {
public:
    int work(int num){
        int sum = 0;
        while (num){
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        
        while (fast != 1){
            fast = work(work(fast));
            slow = work(slow);
            if (fast != 1 && fast == slow) return 0;
        }
        return 1;
    }
};