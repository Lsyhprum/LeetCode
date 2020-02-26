# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mini = triangle[triangle.size() - 1];
        for(int i = triangle.size() - 2; i >= 0; i --){
            for(int j = 0; j < triangle[i].size(); j ++){
                mini[j] = min(mini[j], mini[j + 1]) + triangle[i][j];
            }
        }
        return mini[0];
    }
};

int main(){
    vector<int> v1 = {7};
    vector<int> v2 = {-5, 9};
    vector<int> v3 = {6, 5, 2};
    vector<int> v4 = {-8, -2, -7, 3};
    vector<int> v5 = {-2, 6, -6, -1, 4};
    vector<vector<int>> v = {v1, v2, v3, v4, v5};

    cout << Solution().minimumTotal(v) << "\n";

    return 0;
}