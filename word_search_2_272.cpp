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
    vector<string> res;

    int directions[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    inline bool isValid(int r, int c) {
        return (r >= 0 && r < R) && (c >=0 && c < C);
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        R = board.size();
        C = board[0].size();

        TrieNode * root = new TrieNode();
        for(auto word : words) {
            insert(root, word);
        }

        for(auto r = 0; r < R; r++) {
            for(auto c = 0; c < C; c++) {
                char ch = board[r][c];
                if(root->child[ch] != nullptr) {
                    check_word(root->child[ch], r, c, board, words);
                }
            }
            cout << endl;
        }

        return res;
    }

    void check_word(TrieNode * root, int r, int c, vector<vector<char>>& board, vector<string>& words) {
        if(root->isWord) {
            res.push_back(root->word);
            root->isWord = false;
        }
        char curCh = board[r][c];
        board[r][c] = '.';
        for(auto dir : directions) {
            int nR = r + dir[0];
            int nC = c + dir[1];
            if((nR >= 0 && nR < R) && (nC >=0 && nC < C)) {
                char nextCh = board[nR][nC];
                if(nextCh != '.') {
                    if(root->child[nextCh] != nullptr) {
                        check_word(root->child[nextCh], nR, nC, board, words);
                    }
                }
            }
        }
        board[r][c] = curCh;
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
    //vector<string> words{"oath","pea","eat","rain", "e", "l", "z"};

    vector<string> words {"aaaaaaaaaa","aaaaaaaaab","aaaaaaaaac","aaaaaaaaad","aaaaaaaaae","aaaaaaaaaf","aaaaaaaaag","aaaaaaaaah","aaaaaaaaai","aaaaaaaaaj"};
    //vector<string> words{"e", "a", "l", "z"};
    Solution soln;

    // vector<vector<char>> wordmap {
    //     {'o','a','a','n','o'},
    //     {'e','t','a','e','o'},
    //     {'i','h','k','r','o'},
    //     {'i','f','l','v','o'}}; 


    vector<vector<char>> wordmap {{'m','b','c','d','e','f','g','h','i','j','k','l'},{'n','a','a','a','a','a','a','a','a','a','a','a'},{'o','a','a','a','a','a','a','a','a','a','a','a'},{'p','a','a','a','a','a','a','a','a','a','a','a'},{'q','a','a','a','a','a','a','a','a','a','a','a'},{'r','a','a','a','a','a','a','a','a','a','a','a'},{'s','a','a','a','a','a','a','a','a','a','a','a'},{'t','a','a','a','a','a','a','a','a','a','a','a'},{'u','a','a','a','a','a','a','a','a','a','a','a'},{'v','a','a','a','a','a','a','a','a','a','a','a'},{'w','a','a','a','a','a','a','a','a','a','a','a'},{'x','y','z','a','a','a','a','a','a','a','a','a'}};



                         
    vector<string> res = soln.findWords(wordmap, words);

    for(auto str : res) {
        cout << str << endl;
    }
    cout << endl;
    return 0;
}