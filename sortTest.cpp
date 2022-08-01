#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class FileName {
public:
    string pullPath;
    string dirName;

    FileName(string f, string d) : pullPath(f), dirName(d) {}

  bool operator <(const FileName& rhs)
  {
    return this->dirName > rhs.dirName;
  }
};

int main() {
    vector<FileName> vec;
    FileName f0("a/b/c", "2000");
    FileName f1("a/b/c", "2010");
    FileName f2("a/b/c", "2020");
    FileName f3("a/b/c", "2030");
    vec.push_back(f0);
    vec.push_back(f1);
    vec.push_back(f2);
    vec.push_back(f3);

    sort(vec.begin(), vec.end());

    for(FileName f : vec) {
        cout << f.pullPath << " " << f.dirName << endl;
    }

}