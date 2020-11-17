#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res ;
        queue<vector<int>> st;
        vector<vector<bool>> flags(R, vector<bool>(C, false));
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        st.push(vector<int>{r0, c0});
        flags[r0][c0] = true;

        while(!st.empty()) {
            vector<int> tmp = st.front();
            st.pop();
            res.push_back(tmp);

            for(int i = 0; i < 4; i ++) {
                int row = tmp[0] + direction[i][0];
                int col = tmp[1] + direction[i][1];

                if(row >= 0 && row < R && col >= 0 && col < C && !flags[row][col]) {
                    flags[row][col] = true;
                    st.push(vector<int>{row, col});
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> res = sol.allCellsDistOrder(2, 3, 1, 2);
    for(auto i : res) {
        std::cout << i[0] << "|" << i[1] << " ";
    }
    std::cout << std::endl;
    return 0;
}