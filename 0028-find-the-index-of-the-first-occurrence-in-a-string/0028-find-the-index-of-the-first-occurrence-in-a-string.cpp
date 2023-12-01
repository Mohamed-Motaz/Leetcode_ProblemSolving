class Solution {
public:
    int strStr(string haystack, string needle) {
        
        for (int i = 0; i < haystack.size(); i++){
            int cur = i;
            for (int j = 0; j < needle.size(); j++){
                if (haystack[cur] != needle[j])
                    break;
                
                cur++;
                if (j == needle.size() - 1)
                    return i;
            }
        }
        
        return -1;
    }
};