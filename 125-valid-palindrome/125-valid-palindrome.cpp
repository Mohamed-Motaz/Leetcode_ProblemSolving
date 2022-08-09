class Solution {
public:
    bool isPalindrome(string s) {
        
        string t;
        for (auto e: s)
            if (isOk(e))
                t += tolower(e);

        return isPali(t);
    }
    bool isOk(char c){
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');

    }

    bool isPali(string s){
        for (int i = 0; i < s.size() / 2; i++)
            if (s[i] != s[s.size() - i - 1])
                return false;

        return true;
    }
};