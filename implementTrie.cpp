// simpler implementation of trie

class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        this->isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (char& c : word) {
            int index = c - 'a';
            if (!p->child[index]) {
                p->child[index] = new TrieNode();
            }
            p = p->child[index];
        }
        p->isWord = true;
    }

    bool search(string word, bool prefix = false) {
        TrieNode* p = root;
        for (char& c : word) {
            int index = c - 'a';
            if (!p->child[index]) {
                return false;
            }
            p = p->child[index];
        }
        // end early if only need prefix
        return (prefix) ? true : p->isWord;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
