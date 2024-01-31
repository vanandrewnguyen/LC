// use trie data struct...

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
public:
    TrieNode(char val) {
        this->data = val;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        this->isTerminal = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int idx = word[0] - 'a'; // grab char index
        TrieNode* child = nullptr;
        if (root->children[idx] == nullptr) {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        } else {
            child = root->children[idx];
        }

        // recurse until word is complete
        insertWord(child, word.substr(1));
    }
    
    void addWord(string word) {
        insertWord(root, word);
    }

    bool findWord(TrieNode* root, string word) {
        // word has ended, is root an end node?
        if (word.length() == 0) {
            return root->isTerminal;
        }
        // wild card . can be any letter
        if (word[0] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != nullptr && findWord(root->children[i],word.substr(1))){
                    return true;
                }
            }
        } else {
            // recurse if children of trienode has matching word
            int idx = word[0] - 'a';
            TrieNode *child = nullptr;
            if (root->children[idx] == nullptr) {
                return false;
            } else{
                child = root->children[idx];
            }
            return findWord(child ,word.substr(1));
        }
        return false;   
    }
    
    bool search(string word) {
        return findWord(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
