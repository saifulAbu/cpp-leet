#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        int f = 0;
        int b = s.size() - 1;
       // cout << isVowel('a');
        //cout << isVowel('A');
        //cout << isVowel('z');
        while(f < b) {
            while (f < b && !isVowel(s[f]))
                f++;
            while (f < b && !isVowel(s[b]))
                b--;
            swap(s[f++], s[b--]);
        }
        return s;
    }

private:
    void swap(char & a, char & b) {
        char t = a;
        a = b;
        b = t;
    }

    bool isVowel(char ch) {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }
};


int main() {
    Solution soln;
    cout << soln.reverseVowels("mynameis");
}
