#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int land = 0;
        int border = 0;

        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(grid[i][j] == 1) {
                    land ++;

                    if(i + 1 < grid.size() && grid[i + 1][j] == 1) border ++;
                    if(j + 1 < grid[0].size() && grid[i][j + 1] == 1) border ++; 
                }
            }
        }

        return land * 4 - border * 2;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> island = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    std::cout << sol.islandPerimeter(island);

    return 0;
}