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
    int R, C;
    vector<vector<char>>* BOARD;
    vector<string>* WORDS;

    int directions[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    char at(int r, int c) {
        return (BOARD->at(r)).at(c);
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        BOARD = &board;
        WORDS = &words;
        R = board.size();
        C = board.at(0).size();
        cout << "R: " << R << " C: " << C << endl;

        TrieNode * root = new TrieNode();
        vector<string> res;
        for(auto word : words) {
            insert(root, word);
        }
   
        for(auto vec : board) {
            for(auto ch : vec) {
                cout << ch;
            }
            cout << endl;
        }

        cout << endl;

        for(auto r = 0; r < R; r++) {
            for(auto c = 0; c < C; c++) {
                cout << at(r, c);
            }
            cout << endl;
        }
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
    vector<string> words{"oath","pea","eat","rain"};
    Solution soln;

    vector<vector<char>> wordmap {
        {'o','a','a','n','o'},
        {'e','t','a','e','o'},
        {'i','h','k','r','o'},
        {'i','f','l','v','o'}}; 

                         
    soln.findWords(wordmap, words);
    return 0;
}