#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        if(numRows < 1) return ans;

        ans.push_back({1});

        for(int i = 1; i < numRows; i ++){
            vector<int> v(i+1);
            for(int j = 0; j <= i; j ++){
                if(j-1 >= 0)
                    v[j] += ans[ans.size()-1][j-1];
                if(j < i){
                    v[j] += ans[ans.size()-1][j];
                }
            }
            ans.push_back(v);
        }

        return ans;

        // 1
        // 1 1
        // 1 2 1
        // 1 3 3 1
        // 1 4 6 4 1
    }
};

int main(){
    Solution sol;

    for(auto v : sol.generate(5)){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}