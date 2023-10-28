class TrieNode{
  public:
    int wordEnd;
    int childrenCount = 0;
    const int CAP = 26;
    vector<TrieNode*> children;
    
    TrieNode(){
        children.resize(CAP, nullptr);
    }
    
    void addWord(TrieNode* node, string word){
        for (char c: word){
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node->wordEnd++;
            node->childrenCount++;
            node = node->children[c - 'a'];
        }
        node->wordEnd++;
        node->childrenCount++;
    }
    string getLongestPref(TrieNode* node, vector<string>& strs){
        string ans = "";
        bool found = 1;
        while (found){
            found = 0;
            for (int i = 0; i < CAP; i++){
                TrieNode* child = node->children[i];
                if (child && child->childrenCount == strs.size()){
                    cout << i << endl;
                    ans += ('a' + i);
                    node = child;
                    found = 1;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    string solveTrie(vector<string>& strs){
        TrieNode* root = new TrieNode();
        for (string &s: strs) root->addWord(root, s);
        return root->getLongestPref(root, strs);
    }
    string sortSol(vector<string>& strs){
        sort(strs.begin(), strs.end());
        const int n = strs[0].size();
        const int m = strs.back().size();
        string ans = "";
        for (int i = 0; i < min(n, m); i++){
            if (strs[0][i] != strs.back()[i])
                return ans;
            ans += strs[0][i];
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        //return sortSol(strs);
        return solveTrie(strs);
    }
};