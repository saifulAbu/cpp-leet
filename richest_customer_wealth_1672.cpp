#include<vector>

using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxW = 0;
        for(auto account : accounts) {
            auto curWealth = sumIndividualCustomer(account);
            maxW = max(curWealth, maxW);
        }
        return maxW;
    }

    int sumIndividualCustomer(vector<int> & account) {
        int sum = 0;
        for(auto money : account) {
            sum += money;
        }
        return sum;
    }
};