class TrieNode{
private:
    const int CAP = 26;
public:
    vector<TrieNode*> children;
    int wordEnd;
    TrieNode(){
        children.resize(CAP, NULL);
        wordEnd = 0;
    }
};


class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* copy = root;
        for (char c: word){
            if (!copy->children[c - 'a'])
                copy->children[c - 'a'] = new TrieNode();
            copy = copy->children[c - 'a'];
        }
        copy->wordEnd++;
    }
    
    bool solve(TrieNode* root, int idx, string word){
        if (idx == word.size()){
            return root->wordEnd;
        } 
        if (word[idx] == '.'){
            for (TrieNode* child: root->children){
                if (child){
                    if (solve(child, idx + 1, word))
                        return 1;
                }
            }
            return 0;
        }
        
        if (!root->children[word[idx] - 'a'])
            return 0;
        return solve(root->children[word[idx] - 'a'], idx + 1, word);

    }    
    bool search(string word) {
        
        return solve(root, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */