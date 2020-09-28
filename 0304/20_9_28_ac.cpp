#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {

        if(matrix.size() > 0 && matrix[0].size() > 0) {
            sum.resize(matrix.size());
            for(int i = 0; i < matrix.size(); i ++) {
                sum[i].resize(matrix[0].size());
            }

            sum[0][0] = matrix[0][0];

            for(int i = 1; i < matrix.size(); i ++) 
                sum[i][0] = sum[i-1][0] + matrix[i][0]; 

            for(int j = 1; j < matrix[0].size(); j ++) 
                sum[0][j] = sum[0][j - 1] + matrix[0][j];

            for(int i = 1; i < matrix.size(); i ++) {
                for(int j = 1; j < matrix[0].size(); j ++) {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] + matrix[i][j] - sum[i-1][j-1];
                }
            }
        }

        // for(int i = 0; i < sum.size(); i ++) {
        //     for(int j = 0; j < sum[0].size(); j ++) {
        //         std::cout << sum[i][j] << " ";
        //     } 
        //     std::cout << std::endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sum[row2][col2];
        //std::cout <<res << std::endl;
        
        if(row1 - 1 >= 0 && col1 - 1 >= 0) {
            res += sum[row1-1][col1-1];
        }
        //std::cout <<res << std::endl;

        if(row1 - 1 >= 0) {
            res -= sum[row1-1][col2];
        }
        //std::cout <<res << std::endl;

        if(col1 - 1 >= 0) {
            res -= sum[row2][col1-1];
        }
        //std::cout <<res << std::endl;

        return res;
    }

private:
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    // vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, 
    //                               {5, 6, 3, 2, 1},
    //                               {1, 2, 0, 1, 5},
    //                               {4, 1, 0, 1, 7},
    //                               {1, 0, 3, 0, 5}};
    vector<vector<int>> matrix = {{}};
    NumMatrix* obj = new NumMatrix(matrix);

    //int param_1 = obj->sumRegion(1, 2, 2, 4);
    //std::cout << param_1 << std::endl;
    
    return 0;
}