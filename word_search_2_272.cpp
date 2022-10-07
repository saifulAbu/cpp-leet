#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

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
    vector<string> res;
    set<string> hashset;

    int directions[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    char at(int r, int c) {
        return (BOARD->at(r)).at(c);
    }

    void set(int r, int c, char ch) {
        (BOARD->at(r))[c] = ch;
    }

    bool isValid(int r, int c) {
        return (r >= 0 && r < R) && (c >=0 && c < C);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        BOARD = &board;
        WORDS = &words;
        R = board.size();
        C = board.at(0).size();

        TrieNode * root = new TrieNode();
        for(auto word : words) {
            insert(root, word);
        }

        for(auto r = 0; r < R; r++) {
            for(auto c = 0; c < C; c++) {
                char ch = at(r, c);
                if(root->child[ch] != nullptr) {
                    check_word(root->child[ch], r, c);
                }
            }
            cout << endl;
        }

        std::vector<string> v(hashset.begin(), hashset.end());
        return  v;
    }

    void check_word(TrieNode * root, int r, int c) {
        if(root->isWord) {
            hashset.insert(root->word);
            return;
        }
        char curCh = at(r, c);
        set(r, c, '.');
        for(auto dir : directions) {
            int nR = r + dir[0];
            int nC = c + dir[1];
            if(isValid(nR, nC)) {
                char nextCh = at(nR, nC);
                if(nextCh != '.') {
                    if(root->child[nextCh] != nullptr) {
                        check_word(root->child[nextCh], nR, nC);
                    }
                }
            }
        }
        set(r, c, curCh);
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
    vector<string> words{"oath","pea","eat","rain", "e", "l", "z"};
    //vector<string> words{"e", "a", "l", "z"};
    Solution soln;

    vector<vector<char>> wordmap {
        {'o','a','a','n','o'},
        {'e','t','a','e','o'},
        {'i','h','k','r','o'},
        {'i','f','l','v','o'}}; 

                         
    vector<string> res = soln.findWords(wordmap, words);

    for(auto str : res) {
        cout << str << endl;
    }
    cout << endl;
    return 0;
}