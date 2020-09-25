#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rows = 0, cols = 0;
    int times = 0;

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int start_row = -1, start_col = -1;

        for(int i = 0; i < rows; i ++) {
            for(int j = 0; j < cols; j ++) {
                if(grid[i][j] == 1) {
                    start_row = i;
                    start_col = j;
                }
                if(grid[i][j] == 0) {
                    times += 1;
                }
            }
        }
        times += 2;

        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));

        int res = 0;
        dfs(grid, visited, start_row, start_col, res, 1);

        return res;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col, int &res, int num) {
        //std::cout << row << " " << col << " " << num << std::endl;
        // 到达终点
        if(grid[row][col] == 2) {
            //std::cout << num << std::endl;
            if(num == times)
                res += 1;
            return;
        }

        visited[row][col] = true;

        vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < direction.size(); i ++){
            if((row + direction[i][0] >= rows) || (row + direction[i][0] < 0) 
                    || (col + direction[i][1] >= cols) || (col + direction[i][1] < 0) 
                    || visited[row + direction[i][0]][col + direction[i][1]] 
                    || grid[row + direction[i][0]][col + direction[i][1]] == -1) {
                continue;
            }

            dfs(grid, visited, row + direction[i][0], col + direction[i][1], res, num + 1);
            visited[row + direction[i][0]][col + direction[i][1]] = false;
        }
        
    }
};

int main(){
    Solution sol;

    vector<vector<int>> v = {{0, 1},
                             {2, 0}};

    std::cout << sol.uniquePathsIII(v);

    return 0;
}