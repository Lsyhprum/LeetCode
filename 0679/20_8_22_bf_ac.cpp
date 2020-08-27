#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        // + : 1,23 ... 12,12
        // - : 24,0 25,1 26,2 27,3 .. 81,57
        // * : 3,8  4,6 24,1
        // / : 24,1 48,2 72,3 

        unordered_map<int, unordered_map<int, int> > table_add;
        unordered_map<int, unordered_map<int, int> > table_minus;
        unordered_map<int, unordered_map<int, int>> table_product;
        unordered_map<int, unordered_map<int, int>>  table_division;

        // + 
        for(int i = 1; i <= 9; i ++){
            for(int j = 1; j <= i; j ++){
                table_add[i+j][j] = i;
                table_minus[i-j][j] = i;
                table_minus[j-i][j] = i;
                table_product[j*i][j] = i;
                table_division[]
            }
        }
    }
};

int main(){

    return 0;
}