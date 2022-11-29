#include<vector>
#include <map>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for (size_t i = 1; i < nums.size(); i++)
        {
            res.push_back(res[i-1] + nums[i]);
        }
        return res;
    }
};