#include<vector>
#include<algorithm>
#include <iostream>

using namespace std;
bool compareVector(vector<int> &v0, vector<int> &v1){
    return v0[1] > v1[1];
}


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compareVector);

        int numUnitsTaken = 0;
        int remainingBox = truckSize;
        while (remainingBox > 0 && boxTypes.size() > 0)
        {
            auto curBox = boxTypes.begin();
            auto boxTaken = min(remainingBox, (*curBox)[0]);
            numUnitsTaken += boxTaken * (*curBox)[1];
            remainingBox -= (*curBox)[0];
            boxTypes.erase(boxTypes.begin());
        }
        
        return numUnitsTaken;
    }
private:
    
};

int main() {
    cout << "hello wrold!" << endl;
    vector<vector<int>> boxTypes {{1,3},{2,2},{3,1}};

    Solution soln;

    auto units = soln.maximumUnits(boxTypes, 8);
    cout << units << endl;
}