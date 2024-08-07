class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;

        trieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:

    trieNode* root;

    Trie(){
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        int idx = word[0] - 'a';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        } else{
            child = new trieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word){
        insertUtil(root, word);
    }


    void printSugg(trieNode* curr, string prefix, vector<string> &temp){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for(char ch='a'; ch<='z'; ch++){
            trieNode* next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSugg(next, prefix, temp);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> findSugg(string str){
        trieNode* prvs = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            prefix.push_back(ch);

            trieNode* curr = prvs->children[ch - 'a'];

            if(curr == NULL){
                break;
            }

            vector<string>temp; 
            printSugg(curr, prefix, temp);

            output.push_back(temp);
            temp.clear();

            prvs = curr;
        }

        return output;
    }
};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* T = new Trie();

    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        T->insert(str);
    }

    return T->findSugg(queryStr);
}