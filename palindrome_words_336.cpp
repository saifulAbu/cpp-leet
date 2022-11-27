#include<vector>
#include <map>
#include<iostream>

using namespace std;

class TrieNode {
public:
    bool isWordNode = false;
    bool hasPalindrome = false;

    int wordId = -1;
    vector<int> palindromeWord;
    map<char, TrieNode *> child;
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode * root = new TrieNode();
        vector<vector<int>> res;
        insertReverseOfWords(words, root);

        //search for pairs
        searchPalindromePair(words, root, res);

        //cout << "hello world" << endl;
        return res;
    }

    bool isPalindromeFromIndex(string str, int s) {
        int e = str.size() - 1;
        while(s < e) {
            if(str[s] != str[e]) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }

    string reversetWord(string str) {
        string rev = str;
        int s = 0;
        int e = rev.size() - 1;
        while(s < e) {
            char ch = rev[s];
            rev[s] = rev[e];
            rev[e] = ch;
            s++;
            e--;
        }
        
        return rev;
    }

    void insertReverseOfWords(vector<string>& words, TrieNode * root) {
        for(int i = 0; i < words.size(); i++) {
            string rev = reversetWord(words[i]);
            insertWord(rev, i, root);
        }
    }

    void insertWord(string word, int wordIndex, TrieNode * root) {
        TrieNode * curroot = root;
        if(word.compare("") == 0) {
            root->isWordNode = true;
            root->wordId = wordIndex;
            root->hasPalindrome = true;
            root->palindromeWord.push_back(wordIndex);
            return;
        }

        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(curroot->child[ch] == nullptr) {
                curroot->child[ch] = new TrieNode();
            }
            curroot = curroot->child[ch];
            if(isPalindromeFromIndex(word, i)) {
                curroot->palindromeWord.push_back(wordIndex);
                curroot->hasPalindrome = true;
            } 
        }
        curroot->wordId = wordIndex;
        curroot->isWordNode = true;
    }

    void searchPalindromePair(vector<string>& words, TrieNode * root, vector<vector<int>> & res) {
        
        for(int i = 0; i < words.size(); i++) {
            searchPalindromePair(words[i], i, root, res);
        }
    }

    void searchPalindromePair(string & word, int wordIndex, TrieNode * root, vector<vector<int>> & res) {
        TrieNode * curroot = root;
        if(curroot->isWordNode && curroot->wordId != wordIndex && isPalindromeFromIndex(word, 0)) {
                vector<int> pair = {wordIndex, curroot->wordId};
                res.push_back(pair);
        }
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            curroot = curroot->child[ch];
            if(curroot == nullptr) {
                return;
            }

            if(curroot->isWordNode && curroot->wordId != wordIndex && isPalindromeFromIndex(word, i)) {
                vector<int> pair = {wordIndex, curroot->wordId};
                res.push_back(pair);
            }
            
        }
        map<char, TrieNode *> &childMap = curroot->child;
        if (childMap.size() != 0) {
            //map<char, TrieNode *> &childMap = curroot->child;
            for(auto it = childMap.begin(); it != childMap.end(); ++it) {
                TrieNode* child = childMap[it->first];
                if (child->hasPalindrome)
                {
                    for (auto palIndx : child->palindromeWord)
                    {
                        vector<int> pair = {wordIndex, palIndx};
                        res.push_back(pair);
                    }
                    
                }
                
            }
        }
    }
};

int main() {
    Solution soln;
    cout << soln.reversetWord("a") << endl;
    cout << soln.reversetWord("ab") << endl;
    cout << soln.reversetWord("abc") << endl;
    cout << soln.reversetWord("abcd") << endl;
    cout << soln.reversetWord("abcde") << endl;
    ///vector<string> words = {"aa", "ab", "ba", "bb", "a", "b"};
    //vector<string> words = {"abcd","dcba","lls","s","sssll"};
    //vector<string> words = {"a","aba"};
    vector<string> words = {"bbcg", "b"};
    soln.palindromePairs(words);
    return 0;
}

