class Solution {
public:
    int minimumOperations(string num) {
        //00 25 50 75
        bool zero = 0;
        bool five = 0;
        bool found = 0;
        int mn = num.size();

        
        
        int cnt = 0;
        //00 50
        for (int i = num.size() - 1; i >= 0; i--){
            if (zero)
                if (num[i] == '0' || num[i] == '5') {found = 1; break;}
            
            if (!zero && num[i] == '0') {zero = 1; continue;}
            cnt++;
        }
        if (found || zero) mn = min(mn, cnt);
        zero = 0, five = 0, cnt = 0, found = 0;

        
        //25 75
        for (int i = num.size() - 1; i >= 0; i--){
            if (five)
                if (num[i] == '2' || num[i] == '7') {found = 1; break; }
            
            if (!five && num[i] == '5') {five = 1; continue;}
            cnt++;
        }
        if (found) mn = min(mn, cnt);


        
        
        return mn;
    }
};