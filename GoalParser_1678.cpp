#include<string>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res = "";
        int i = 0;
        while(i < command.size()) {
            char ch = command[i];
            if(ch == 'G') {
                res += 'G';
                i++;
            } else if (ch == '(') {
                if(command[i+1] == ')') {
                    res += 'o';
                    i += 2;
                } else {
                    res += 'a';
                    res += 'l';
                    i += 4;
                }
            }
        }
        return res;
    }
};

/*
res = ''

while i < len(str)
    cur = str[i]
    if cur == G
        res += G
        i++;
    else if cur == (
        if str[i+1] = ')'
            res += 'o'
            i += 2
        else 
            res += 'al'
            i += 4
        end
    end
end













*/