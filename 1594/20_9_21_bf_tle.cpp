#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long max = -1;
        dfs(grid, 0, 0, 1, max);

        return (max) % (long long)(pow(10, 9) + 7);
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int cur, long long &max) {
        if(row >= grid.size() || col >= grid[0].size()) return;
        
        cur = cur * grid[row][col];
        //std::cout << row << " " << col << " " << cur << std::endl;
        if(row == grid.size() - 1 && col == grid[0].size() - 1) {
            //std::cout << "finish " << std::endl;    
            max = cur > max ? cur : max ;
        }

        vector<vector<int>> direction = {{1, 0}, {0, 1}};

        for(int i = 0; i < 2; i ++) {
            dfs(grid, row + direction[i][0], 
                col + direction[i][1], cur, max);
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{1, 3}, {0, -4}};

    cout << sol.maxProductPath(v);

    return 0;
}