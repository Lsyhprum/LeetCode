# include <iostream>
# include <math.h>
# include <vector>

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // 0 0 1 1    1 1 1 1
        // 1 0 1 0 -> 1 0 0 1
        // 1 1 0 0    1 1 1 1

        // 将每行第一个元素变为 1

        int rows = A.size(), cols = A[0].size();

        if(cols == 1) return rows;

        vector<int> flags(cols, 0);

        bool flag = false;
        for(int row = 0; row < rows; row ++) {
            if(A[row][0] == 0) flag = true;
            for(int col = 0; col < cols; col ++) {
                if(flag) {
                    A[row][col] ^= 1;
                }

                if(A[row][col] == 1) {
                    flags[col] ++;
                }
            }
            flag = false;
        }

        // for(int row = 0; row < rows; row ++) {
        //     for(int col = 0; col < cols; col ++) {
        //         std::cout << A[row][col] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        int res = rows * pow(2, cols - 1);

        for(int col = 1; col < cols; col ++) {
            for(int row = 0; row < rows; row ++) {
                if(flags[col] <= rows / 2) {
                    A[row][col] ^= 1;
                }

                res += (A[row][col] * pow(2, cols - col - 1));
            }
        }

        //std::cout << 3 << std::endl;

        // for(int row = 0; row < rows; row ++) {
        //     for(int col = 0; col < cols; col ++) {
        //         std::cout << A[row][col] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    std::cout << sol.matrixScore(v) << std::endl;
    return 0;
}