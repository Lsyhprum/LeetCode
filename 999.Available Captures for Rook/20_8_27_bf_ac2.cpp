#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(N^2), 100.00%
// time complexity : 58.73%
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // 分为两部分 —— 找到 R 之前， 找到 R 之后
        vector<bool> row_flag(board.size(), false);
        vector<bool> col_flag(board.size(), false);

        int R_row = -1, R_col = -1;

        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board.size(); j ++){
                if(board[i][j] == 'R'){
                    R_row = i;
                    R_col = j;
                    break;
                }else if(board[i][j] == 'p'){
                    row_flag[i] = true;
                    col_flag[j] = true;
                }else if(board[i][j] == 'B'){
                    row_flag[i] = false;
                    col_flag[j] = false;
                }
            }
            if(R_row != -1) break;
        }

        int num = 0;
        if(row_flag[R_row]) num += 1;
        if(col_flag[R_col]) num += 1;

        // 下
        for(int i = R_row + 1; i < board.size(); i ++){
            if(board[i][R_col] == 'p'){
                num ++ ;
                break;
            }else if(board[i][R_col] == 'B'){
                break;
            }
        }

        // 右
        for(int i = R_col + 1; i < board.size(); i ++){
            if(board[R_row][i] == 'p'){
                num ++;
                break;
            }else if(board[R_row][i] == 'B'){
                break;
            }
        }

        return num;
    }
};