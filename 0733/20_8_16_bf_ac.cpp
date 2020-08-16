#include <iostream>
#include <vector>

using namespace std;

// time complexity : 32.65%
// memory complexity : 71.83%
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();

        vector<vector<bool>> flag(rows, vector<bool>(cols, true));

        dfs(image, flag, rows, cols, sr, sc, image[sr][sc], newColor);

        return image;
    }

private:
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& flag, int rows, int cols, int sr, int sc, int oldColor, int newColor){
        if(valid(sr, sc, rows, cols) && flag[sr][sc] && image[sr][sc] == oldColor){
            image[sr][sc] = newColor;
            flag[sr][sc] = false;

            vector<pair<int, int>> direction = {pair<int, int>(0, 1), pair<int, int>(0, -1), pair<int, int>(1, 0), pair<int, int>(-1, 0)};

            for(int i = 0; i < direction.size(); i ++){
                dfs(image, flag, rows, cols, sr+direction[i].first, sc+direction[i].second, oldColor, newColor);
            }
        }
    }

    bool valid(int sr, int sc, int rows, int cols){
        if(sr >=0 && sr < rows && sc >= 0 && sc < cols){
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 1, 2}};
    vector<vector<int>> res = sol.floodFill(image, 0, 0, 1);

    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[0].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}