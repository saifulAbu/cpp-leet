#include<vector>
#include<iostream>
#include <set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = getMax(nums);
        int L = getLen(max);
        cout << "max " << max << " len " << L << endl;

        set<int> hashset;
        //hashset.insert(127);
        int maxXor = 0;
        for(auto i = L - 1; i >= 0; i--) {
            hashset.clear();
            auto candidateMax = maxXor | 1;
            maxXor = maxXor << 1;
            for(auto num : nums) {
                hashset.insert(num >> i); 
            }

            for(auto pref : hashset) {
                if(hashset.count(pref ^ candidateMax) != 0) {
                    maxXor = candidateMax;
                }
            }
        }
        return maxXor; 
    }

    int getMax(vector<int>& nums) {
        int max = nums[0];
        for(auto cur : nums) {
            if(cur > max) {
                max = cur;
            }
        }
        return max;
    }

    int getLen(int num) {
        int i = 0;
        while(num > 0) {
            num = num >> 1;
            i++;
        }
        return i;
    }
};

int main() {
    cout << "hi hi hi " << endl;
    Solution s;
    vector<int> v;
    v.push_back(7);
    v.push_back(4);
    v.push_back(1);
    s.findMaximumXOR(v);    
}