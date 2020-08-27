#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);

        ans[0] = 1;

        // 1
        // 1 1
        // 1 2 1
        // 1 3 3 1
        // 1 4 6 4 1

        for(int i = 1; i <= rowIndex; i ++){
            for(int j = i; j >= 0; j --){
                if(j-1 >= 0)
                    ans[j] += ans[j-1];
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;

    for(auto v : sol.getRow(4)){
        cout << v << " ";
    }
    return 0;
}