#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insertUtil(TrieNode* root, string word) {
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'A';
    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        child = new TrieNode(word[0]);
        root->children[index] = child;
    }

    insertUtil(child, word.substr(1));
}

void insertWord(TrieNode* root, string word) {
    insertUtil(root, word);
}

bool searchUtil(TrieNode* root, string word) {
    if (word.length() == 0) {
        return root->isTerminal;
    }

    int index = word[0] - 'A';
    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        return false;
    }

    return searchUtil(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
    return searchUtil(root, word);
}

bool deleteUtil(TrieNode* root, string word) {
    if (word.length() == 0) {
        if (root->isTerminal) {
            root->isTerminal = false;
            return true;
        }
        return false;
    }

    int index = word[0] - 'A';
    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        return false;
    }

    bool shouldDeleteChild = deleteUtil(child, word.substr(1));

    if (shouldDeleteChild) {
        delete child;
        root->children[index] = NULL;

        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return false;
            }
        }
        return !root->isTerminal;
    }

    return false;
}

void deleteWord(TrieNode* root, string word) {
    deleteUtil(root, word);
}

int main() {
    TrieNode* root = new TrieNode('\0');

    insertWord(root, "HELLO");
    insertWord(root, "WORLD");

    cout << "Search HELLO: " << (searchWord(root, "HELLO") ? "Found" : "Not Found") << endl;
    cout << "Search WORLD: " << (searchWord(root, "WORLD") ? "Found" : "Not Found") << endl;

    deleteWord(root, "HELLO");
    cout << "Search HELLO after deletion: " << (searchWord(root, "HELLO") ? "Found" : "Not Found") << endl;

    return 0;
}
