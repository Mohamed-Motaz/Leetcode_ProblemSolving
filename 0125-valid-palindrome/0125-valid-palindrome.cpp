class Solution {
public:
    bool isValid(char c)
    {
        return (tolower(c) >= 'a' && tolower(c) <= 'z') || (c >= '0' && c <= '9');
    }
    
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            while (!isValid(s[l]) && l < r)
            {
                l++;
            }
            while (!isValid(s[r]) && l < r)
            {
                r--;
            }
            if (tolower(s[r]) != tolower(s[l]))
                return false;
            l++, r--;
        }
        return true;
    }
};