#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        int prev = first;
        for(int i = 0; i < encoded.size(); i++) {
            int cur = encoded[i] | prev;
            res.push_back(cur);
            prev = cur;
        }
        return res;
    }
};