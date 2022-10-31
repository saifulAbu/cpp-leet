#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
using namespace std;

class TrieNode {
    public:
    map<char, TrieNode *> child;
    vector<int>  wordList;
};

class Solution {
public:
    TrieNode * root = new TrieNode;
    vector<vector<string>> result;
    vector<string> * words;
    vector<int> emptyWordList;
    int N;

    vector<vector<string>> wordSquares(vector<string>& words) {
        this->words = &words;
        N = words[0].size();
        //insert to trie
        for(int i = 0; i < words.size(); i++) {
            insertToTrie(words[i], i);
        }

        vector<string> candidate;

        // attempt the current word as the first word
        for(auto word : words) {
            candidate.push_back(word);
            checkSolution(candidate);
            candidate.pop_back();        
        }
        return result;

    }

    void insertToTrie(string & word, int index) {
        TrieNode * curRoot = root;
        curRoot->wordList.push_back(index);
        for(auto ch : word) {
            if(curRoot->child[ch] == nullptr) {
                curRoot->child[ch] = new TrieNode;
            }
            curRoot = curRoot->child[ch];
            curRoot->wordList.push_back(index);
        }
    }

    string formSubString(vector<string> & candidate) {
        string substr;
        int step = candidate.size();
        for(int i = 0; i < step; i++) {
            char ch = candidate[i].at(step);
            substr += ch;
        }
        return substr;
    }

    vector<int>& getCandidateWords(string & prefix) {
        TrieNode * curnroot = root;
        for(auto ch : prefix) {
            curnroot = curnroot->child[ch];
            if(curnroot == nullptr) {
                return emptyWordList;
            }
        }
        return curnroot->wordList;
    }

    void checkSolution(vector<string> & candidate) {
        int step = candidate.size();
        if(step == N) {
            vector<string> copyCandidate = candidate;
            result.push_back(copyCandidate);
            return;
        }
        string substr = formSubString(candidate);
        auto candidateWords = getCandidateWords(substr);
        for(auto candidateWordIndex : candidateWords) {
            candidate.push_back(words->at(candidateWordIndex));
            checkSolution(candidate);
            candidate.pop_back();
        }

    }
};

//TODO: implement check solution function
int main(void) {
    Solution soln;
    vector<string> words = {"area","lead","wall","lady","ball"};
    soln.wordSquares(words);
    cout << "hello wrold" << endl;
}
 
/*
=> insert to trie
TrieNode
    child[]
    wordList[]

//class variable
trieRoot
result
words
    
generateResult    
    candidate

    for(i = 0; i < words.len; i++)
        insertToTrie(word, i)

    for(word : words)
        candidate.insert(word)
        checkSolution(candidate, result, 0)
        candidate.remove() 
    

    checkSolution(candidate, result, step)
        if(step == 4)
            copyCandidate = copy(candidate)
            result.add(copyCandidate)
            return
        subStr = formSubstring(candidate, step+1)
        canidateWords = getCandidateWords(prefix)
        if(candidtateWords == nul)
            return
        for(candidateWord : CandidateWords) 
            candidate.add(candidateWord)
            checkSolution(candidate, result, step + 1)
            candidate.remove()
    

insertToTrie(word, wordIndex)
    curRoot = trieRoot
    for(ch : word)
        if(curRoot.child[ch] == null)
            curRoot.child[ch] = new TrieNode
        curRoot = curRoot.child[ch]
        curRoot.wordList.add(wordIndex)

formSubString(candidate, step)
    subStr = ""
    for(i = 0; i < step; i++)
        subStr += candidate[i][step]
    
    return subStr

getCandidateWords(prefix)
    curRoot = TrieRoot
    for(ch : prefix)
        curRoot = curRoot[ch]
        if(curRoot == null)
            return null
    return curRoot.wordList

*/