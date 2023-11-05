class Solution {
public:   
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        
        int ctr = 1;

        while (q.size()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                string cur = q.front(); q.pop();
                string copy;
                if (cur == endWord) {
                    return ctr;
                }


                for (int i = 0; i < cur.size(); i++){
                    copy = cur;
                    for (char c = 'a'; c <= 'z'; c++){
                        if (c == cur[i]) continue;
                        copy[i] = c;
                        if (words.find(copy) != words.end()){
                            q.push(copy);
                            words.erase(cur);
                        }
                    }
                }
                words.erase(cur);
            }
            

            ctr++;
        }
        
        return 0;
    }
    
};