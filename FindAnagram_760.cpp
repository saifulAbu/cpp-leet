#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;


class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map2;
        for(int i = 0; i < nums2.size(); i++) {
            map2[nums2[i]] = i;
        }
        
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            res.push_back(map2[nums1[i]]);
        }

        return res;
    }
};