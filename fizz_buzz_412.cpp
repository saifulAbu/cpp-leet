#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(auto i = 1; i <= n; i++) {
            res.push_back(getFizzBuzz(i));
        }
        return res;
    }

    string getFizzBuzz(int n) {
        if(n % 15 == 0) {
            return "FizzBuzz";
        } else if (n % 3 == 0) {
            return "Fizz";
        } else if (n % 5 == 0) {
            return "Buzz";
        } else {
            return to_string(n);
        }
    }


};