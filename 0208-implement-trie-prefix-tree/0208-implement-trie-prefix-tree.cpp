class TrieNode{
public:
    const int CAPACITY = 26;
    vector<TrieNode*> children;
    int wordEnd;
    
    TrieNode(){
        children.resize(CAPACITY, NULL);
        wordEnd = 0;
    }
    
    void addWord(TrieNode* root, string s){
        for (char c: s){
            TrieNode* child = root->children[c - 'a'];
            if (!child)
                child = new TrieNode();
            root->children[c - 'a'] = child;
            root = child;
        }
        root->wordEnd++;
    }
    
    bool search(TrieNode* root, string s){
        for (char c: s){
            if (!root->children[c - 'a']) return 0;
            root = root->children[c - 'a'];
        }
        return root->wordEnd > 0;
    }
    
    bool prefix(TrieNode* root, string s){
        for (char c: s){
            if (!root->children[c - 'a']) return 0;
            root = root->children[c - 'a'];
        }
        return 1;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        root->addWord(root, word);
    }
    
    bool search(string word) {
        return root->search(root, word);
    }
    
    bool startsWith(string prefix) {
        return root->prefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */