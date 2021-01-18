#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2) return true;

        if(coordinates[1][0] - coordinates[0][0] == 0) {
            for(int i = 2; i < coordinates.size(); i ++) {
                if(coordinates[i][0] != coordinates[0][0]) return false;
            }
            return true;
        }

        // y = kx + b;
        float k = (coordinates[1][1] - coordinates[0][1]) * 1.0f / (coordinates[1][0] - coordinates[0][0]);
        float b = coordinates[0][1] - k * coordinates[0][0];
        std::cout << k << " " << b << std::endl;

        for(int i = 2; i < coordinates.size(); i ++) {
            if(coordinates[i][0] * k + b != coordinates[i][1]) return false;
        }

        return true;
    }   
};

int main() {
    vector<vector<int>> v = {{2,1},{4,2},{6,3}};
    Solution sol;
    std::cout << sol.checkStraightLine(v);
    return 0;
}