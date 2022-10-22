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
    vector<vector<string>> *result = new vector<vector<string>>;
    vector<string> * words;

    vector<vector<string>> wordSquares(vector<string>& words) {
        this->words = &words;
        //insert to trie
        for(int i = 0; i < words.size(); i++) {
            insertToTrie(words[i], i);
        }

        vector<string> * candidate = new vector<string>;

        // attempt the current word as the first word
        return *result;

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