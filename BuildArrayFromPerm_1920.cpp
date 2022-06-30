#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};

int main() {
    Solution soln;
    vector<int> nums {0,2,1,5,3,4};
    vector<int> res = soln.buildArray(nums);
    cout << "hello";
}