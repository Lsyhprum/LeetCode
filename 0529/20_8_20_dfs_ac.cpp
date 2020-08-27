#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> val = {-1, 1, 0};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int click_row = click[0];
        int click_col = click[1];

        // 挖到地雷，程序终止
        if(board[click_row][click_col] == 'M') {
            board[click_row][click_col] = 'X';
        }else{
            int mine_num = MineNum(board, click_row, click_col);
            if(mine_num == 0){
                // 挖到空白块，递归查找，如果同样为空白块，再次递归， 
                // 如果不是空白块，查询周边地雷数
                
                for(int rv : val){
                    for(int cv : val){
                        
                    }
                }

                updateBoard(board, )

            }else{
                // 如果不是空白块， 修改数字（函数封装)
                board[click_row][click_col] = '0' + mine_num; 
            }
        }
        return board;
    }

    int MineNum(vector<vector<char>> &board, int row, int col){
        int num = 0;
        for(int rv : val){
            for(int cv : val){
                int new_row = row + rv;
                int new_col = col + cv;
                if(new_row >= 0 && new_row < board.size() &&
                        new_col >= 0 && new_col < board[0].size() &&
                            board[new_row][new_col] == 'M'){
                    num += 1;
                }
            }
        }

        return num;
    }

    void DFS(vector<vector<char>>& board, int row, int col){

    }
};

int main(){

    Solution sol;
    vector<vector<char>> board = {
        {'E', 'E', 'E', 'E', 'E'}, 
        {'E', 'E', 'M', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'},
        {'E', 'E', 'E', 'E', 'E'}};

    cout << sol.MineNum(board, 0, 1);

    vector<int> click = {3, 0};
    sol.updateBoard(board, click);

    return 0;
}