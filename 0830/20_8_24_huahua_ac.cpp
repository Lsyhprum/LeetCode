#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(N), 51.35%
// memory complexity : O(N), 48.78%
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        constexpr int kLargeGroupSize = 3;

        vector<vector<int>> res;

        const int len = S.size();

        int c = 0;

        for(int i = 0; i <= len; ++ i, ++ c){
            if(i == len || S[i] != S[i-1]) {
                if(c >= kLargeGroupSize) 
                    res.push_back({i-c, i-1});
                c = 0;
            }
        }
        return res;
    }
};

int main(){

    Solution sol;
    string S = "abbxxxxzzy";
    vector<vector<int>> res = sol.largeGroupPositions(S);

    for(auto v : res){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}