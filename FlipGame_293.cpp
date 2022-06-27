#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;

        for(int i = 0; i < currentState.size() - 1; i++) {
            if(currentState.at(i) == '+' && currentState.at(i+1) == '+') {
                string newStr(currentState);
                newStr[i] = '-';
                newStr[i+1] = '-';
                res.push_back(newStr);
            }
        }
        return res;
    }
};

int main() {
    cout << "hello wrold" << endl;
    Solution sln;
    vector<string> res = sln.generatePossibleNextMoves(string("++++"));
    cout << "hello" << endl;
}