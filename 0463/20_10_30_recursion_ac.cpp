#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i = 0; i < grid.size(); i ++) {
            for(int j = 0; j < grid[0].size(); j ++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid, visited, res);
                }
            }
        }

        return res;
    }

private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &res) {
        //std::cout << row << " " << col << std::endl;
        visited[row][col] = true;

        res += 4;

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i = 0; i < 4; i ++) {
            int new_row = row + direction[i][0];
            int new_col = col + direction[i][1];

            if(new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size()) { 
                if(visited[new_row][new_col] && grid[new_row][new_col] == 1)
                    res -= 2;
            }
        }

        for(int i = 0; i < 4; i ++) {
            int new_row = row + direction[i][0];
            int new_col = col + direction[i][1];

            if(new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size()) { 
                if(visited[new_row][new_col] == false && grid[new_row][new_col] == 1)
                    dfs(new_row, new_col, grid, visited, res);
            }
        }
    }
};

int main() {

    Solution sol;
    vector<vector<int>> island = {{1, 1}, {1, 1}};
    std::cout << sol.islandPerimeter(island);

    return 0;
}