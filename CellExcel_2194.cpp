#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c0 = s[0];
        int r0 = s[1] - '0';
        char c1 = s[3];
        int r1 = s[4] - '0';
        vector<string> res;

        for(char c = c0; c <= c1; c++) {
            for(int r = r0; r <= r1; r++) {
                string cur{c};
                cur = cur + to_string(r);
                res.push_back(cur);
            }
        }

        return res;
    }
};

