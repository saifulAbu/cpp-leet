#include<vector>
#include<iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWord = 0;
        for(auto itr = sentences.begin(); itr != sentences.end(); itr++) {
            maxWord = max(maxWord, getNumWords(*itr));
        }
        return maxWord;
    }

    int getNumWords(string str) {
        stringstream ss(str); //convert my_string into string stream
        int count = 0;
        string temp_str;

        while(getline(ss, temp_str, ' ')){ //use space as delim for cutting string
            count++;
        }        
        return count;
    }
};

int main() {

}