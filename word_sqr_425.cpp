#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>
using namespace std;

class TrieNode {
    map<char, TrieNode> child;
    vector<int>  *wordList;

    TrieNode() {
        wordList = new vector<int>();
    }
};

class Solution {
public:
    TrieNode * root;
    vector<vector<string>> *result = new vector<vector<string>>;
    vector<string> * words;

    Solution() {

    }


    vector<vector<string>> wordSquares(vector<string>& words) {
        this->words = &words;
        vector<string> * candidate = new vector<string>;

        // attempt the current word as the first word
        return *result;

    }
};

int main(void) {
    Solution soln;
    cout << soln.wordSquares();
    cout << "hello wrold" << endl;
}
 
/*
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