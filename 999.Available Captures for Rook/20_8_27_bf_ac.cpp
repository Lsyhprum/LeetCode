#include <iostream>
#include <vector>

using namespace std;

// time complexity : 49.44%
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row = 0, col = 0;
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board.size(); j ++){
                if(board[i][j] == 'R'){
                    row = i;
                    col = j;
                }
            }
        }

        int num = 0;

        // 上
        for(int i = row - 1; i >= 0; i --){
            if(board[i][col] == 'p'){
                num ++ ;
                break;
            }else if(board[i][col] == 'B'){
                break;
            }
        }

        // 下
        for(int i = row + 1; i < board.size(); i ++){
            if(board[i][col] == 'p'){
                num ++ ;
                break;
            }else if(board[i][col] == 'B'){
                break;
            }
        }

        // 左
        for(int i = col - 1; i >= 0; i --){
            if(board[row][i] == 'p'){
                num ++;
                break;
            }else if(board[row][i] == 'B'){
                break;
            }
        }

        // 右
        for(int i = col + 1; i < board.size(); i ++){
            if(board[row][i] == 'p'){
                num ++;
                break;
            }else if(board[row][i] == 'B'){
                break;
            }
        }

        return num;
    }
};