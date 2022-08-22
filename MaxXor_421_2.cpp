#include<vector>
#include <map>
#include<iostream>

using namespace std;

class TrieNode {
    map<int, TrieNode> child;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
     int maxLen = getLen(getMax(nums));   
     TrieNode root;
     for(auto num : nums) {
        insertToTrie(root, num, maxLen);
     }
     return 0;
    }

    void insertToTrie(TrieNode root, int num, int maxLen) {
        int andBit = 1 << (maxLen - 1);
        cout << andBit << endl;
        cout << "inserting " << num << endl;
        for(int i = 0; i < maxLen; i++) {
            int curBit = (andBit & num) >> (maxLen - i - 1);
            andBit = andBit >> 1;
            cout << curBit;
        }
        cout << endl;
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
    vector<int> vect{3,10,5,25,2,8};
    Solution soln;
    soln.findMaximumXOR(vect);
}