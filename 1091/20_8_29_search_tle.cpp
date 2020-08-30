#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> cost;

        int INF = INT_MAX;

        for(auto &row : grid){
            for(auto &val : row){
                if(val) val = INF;
            }
        }

        if(grid[0][0] == INF || grid[grid.size() - 1][grid.size() - 1] == INF) return -1;

        grid[0][0] = 1;

        // bfs
        vector<int> direction = {-1, 0, 1};
        queue<pair<pair<int, int>, int>> q;

        q.push(pair<pair<int, int>, int>(pair<int, int>(0, 0), 1));

        while(!q.empty()){
            int step = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;

            q.pop();

            for(const auto& r : direction){
                for(const auto& c : direction){
                    if(legal(grid, row + r, col + c) &&  grid[row + r][col + c] != INF && grid[row + r][col + c] == 0){
                        grid[row + r][col + c] = step + 1;
                        q.push(pair< pair<int, int>, int> ({row + r, col + c}, step + 1));
                        //cout << row + r << " " << col + c << " " << step + 1<< endl;
                    }
                }
            }

        }

        // for(auto r : grid){
        //     for(auto i : r){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }

        return grid[grid.size()-1][grid.size()-1] == 0 ? -1 : grid[grid.size() - 1][grid.size() - 1];
    }

private:
    bool legal(const vector<vector<int>> grid, int row, int col){
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid.size())
            return true;

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}};
    
    cout << sol.shortestPathBinaryMatrix(grid);
    return 0;
}