#include <iostream>

using namespace std;

class NimGame_292 {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    NimGame_292 sln;
     std::cout << sln.canWinNim(4) << endl;
    std::cout << "hello world" << std::endl;
}