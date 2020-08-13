#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board.size();

        for(int i = 0; i < rows; i ++){
            travel(board, i, 0);
            travel(board, i, cols-1);
        }

        for(int i = 0; i < cols; i ++){
            travel(board, 0, i);
            travel(board, rows-1, i);
        }

        // for(int i = 0; i < rows; i ++){
        //     for(int j = 0; j < cols; j ++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i < rows; i ++){
            for(int j = 0; j < cols; j ++){
                if(board[i][j] == 'F'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

private:
    void travel(vector<vector<char>>& board, int row, int col){
        //cout << row << " " << col << endl;
        if(row >= 0 && row < board.size() && col >= 0 && col < board[0].size()){
            if(board[row][col] == 'X'){
                //cout << "X" << endl;
                return;
            }else{
                board[row][col] = 'F';
                travel(board, row - 1, col);
                travel(board, row + 1, col);
                travel(board, row, col - 1);
                travel(board, row, col + 1);
            }
        }
    }

};

int main(){
    vector<vector<char>> board = 
    {{'O', 'O'},
    {'O', 'O'}};
        // {{'X', 'X', 'X', 'X'},
        //  {'X', 'O', 'O', 'X'},
        //  {'X', 'X', 'O', 'X'},
        //  {'X', 'O', 'X', 'X'}};

    Solution sol;
    
    int row = board.size();
    int col = board[0].size();

    sol.solve(board);

    for(int i = 0; i < row; i ++){
        for(int j = 0; j < col; j ++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}