#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int v0 = 0;
        int v1 = 0;

        for(auto num : nums) {
            auto curMax = max(v0 + num, v1);
            v0 = v1;
            v1 = curMax;
        }
        return v1;
    }
};