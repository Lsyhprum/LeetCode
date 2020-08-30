#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len = grid.size();

        if(grid[0][0] == 1 || grid[len - 1][len - 1] == 1) return -1;
        
        vector<vector<int> >cost(len, vector<int>(len, 0));

        cost[0][0] = 1;

        vector<int> direction = {-1, 0, 1};
        queue<pair<int, int>> q;

        q.push(pair<int, int>(0, 0));

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int step = cost[row][col] + 1;

            q.pop();

            for(const auto& r : direction){
                for(const auto& c : direction){
                    if(legal(grid, cost, row + r, col + c)){
                        cost[row + r][col + c] = step;
                        if(row + r == len -1 && col + c == len - 1)
                            return cost[row + r][col + c];
                        q.push(pair<int, int> (row + r, col + c));
                        //cout << row + r << " " << col + c << " " << step + 1<< endl;
                    }
                }
            }

        }

        return cost[len - 1][len - 1] == 0 ? -1 : cost[len-1][len-1];
    }

private:
    bool legal(const vector<vector<int>> &grid, const vector<vector<int>> &cost, int row, int col){
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid.size() && cost[row][col] == 0 && grid[row][col] != 1)
            return true;

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{0}};
    
    cout << sol.shortestPathBinaryMatrix(grid);
    return 0;
}