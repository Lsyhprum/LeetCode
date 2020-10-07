#include <iostream>
#include <vector>

using namespace std;

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i = row1; i <= row2; i ++) {
            for(int j = col1; j <= col2; j ++) {
                rec[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rec[row][col];
    }

private:
    vector<vector<int>> rec;
};


int main() {
    vector<vector<int>> rectangle = {{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}};
    SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
    std::cout << obj->getValue(0, 2);
    obj->updateSubrectangle(0, 0, 3, 2, 5);
    int param_2 = obj->getValue(0, 2);

    std::cout << param_2 << std::endl;


    return 0;
}