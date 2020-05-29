# include <iostream>
# include <vector>

using namespace std;
/**
 * 00  01  02
 * 10  11  12
 * 20  21  22
 * 
 **/
// 02 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();

        // 调换对角
        for(int i = 0; i < len; i ++){
            for(int j = 0; j < len - i; j ++){       // 防止重复交换
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[len - j - 1][len - i - 1];
                matrix[len - j - 1][len - i - 1] = tmp;
            }
        }

        // 调换行
        for(int i = 0; i < len / 2; i ++){
            for(int j = 0; j < len; j ++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[len - i - 1][j];
                matrix[len - i - 1][j] = tmp;
            }
        }
    }
};

int main(){
    vector<vector<int>> v = {{5, 1, 9,11}, {2, 4, 8,10}, {13, 3, 6, 7}, {15,14,12,16}};
    Solution sol;

    sol.rotate(v);

    for(int i = 0; i < v.size(); i ++){
        for(int j = 0; j < v[0].size(); j ++){
            cout << v[i][j ] << " ";
        }
        cout << endl;
    }
    
    return 0;
}