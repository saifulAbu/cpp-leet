#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
class TrieNode {
    public:
        map<char, TrieNode*> child;
        bool isWord;
        string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode * root = new TrieNode();
        vector<string> res;
        for(auto word : words) {
            insert(root, word);
        }
        cout << "done" << endl;
        return res;
    }

    void insert(TrieNode * root, string word) {
        for(auto ch : word) {
            if(root->child[ch] == nullptr) {
                root->child[ch] = new TrieNode();
            }
            root = root->child[ch];
        }
        root->isWord = true;
        root->word = word;
    }
};

int main() {
    vector<string> words{"a","ab","aba","abb"};
    Solution soln;
    vector<vector<char>> wordmap;
    soln.findWords(wordmap, words);
    return 0;
}