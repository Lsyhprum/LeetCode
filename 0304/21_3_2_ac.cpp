#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) {
            empty = true;
            return;
        }

        table.resize(matrix.size() + 1);

        for(int i = 0; i < matrix.size() + 1; i ++) {
            table[i].resize(matrix[0].size() + 1);
        }

        for(int j = 0; j < matrix.size(); j ++) {
            table[j][0] = 0;
        }

        for(int i = 0; i < matrix[0].size(); i ++) {
            table[0][i] = 0;
        }

        if(matrix.size() == 1 && matrix[0].size() == 0) {
            empty = true;
            return;
        }

        for(int i = 0; i < matrix.size(); i ++) {
            for(int j = 0; j < matrix[0].size(); j ++) {
                table[i + 1][j + 1] = table[i][j] + matrix[i][j];

                for(int n = 0; n < i; n ++) {
                    table[i + 1][j + 1] += matrix[n][j];
                }

                for(int m = 0; m < j; m ++) {
                    table[i + 1][j + 1] += matrix[i][m];
                }
            }
        }

        for(int i = 0; i < matrix.size() + 1; i ++) {
            for(int j = 0; j < matrix[0].size() + 1; j ++) {
                std::cout << table[i][j] << " ";
            }
            std::cout << std::endl;
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(empty) return 0;

        int result = table[row2 + 1][col2 + 1];

        if(row1 > 0) {
            result -= table[row1][col2 + 1];
        }

        if(col1 > 0) {
            result -= table[row2 + 1][col1];
        }

        if(row1 > 0 && col1 > 0) {
            result += table[row1][col1];
        }

        return result;
    }

private:
    vector<vector<int>> table;
    bool empty = false;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> matrix = {{}};

    // vector<vector<int>> matrix = {{}};

    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(0, 3, 0, 4);

    std::cout << param_1 << std::endl;
    return 0;
}