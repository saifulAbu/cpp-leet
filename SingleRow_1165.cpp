#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char, int> kmap;
        for(int i = 0; i < keyboard.size(); i++) {
            kmap[keyboard[i]] = i;
        }
        
        int prev = 0;
        int res = 0;
        for(int i = 0; i < word.size(); i++) {
            int cur = kmap[word[i]];
            res += abs(cur - prev);
            prev = cur;
        }
        return res;
    }
};

