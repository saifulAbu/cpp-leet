#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto num : nums) {
            map[num]++;
        }
        auto res = 0;
        for(auto keyVal : map) {
            auto c = keyVal.second;
            res += (c * (c - 1)) / 2;
        }
        return res;
    }
};