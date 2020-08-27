#include <iostream>
#include <vector>

using namespace std;

// time complexity : O(N), 51.35%
// memory complexity : O(N), 48.78%
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;

        int len = S.size();

        if(len < 2) return res;

        int left = 0, right = 0;

        while(right < len){
            if(S[left] == S[right]){
                right ++;
            }else{
                if((right-1) - left >= 2){
                    vector<int> tmp = {left, right-1};
                    res.push_back(tmp);
                }
                left = right;
            }
        }
        if((right-1) - left >= 2){
            vector<int> tmp = {left, right-1};
            res.push_back(tmp);
        }

        return res;
    }
};

int main(){

    Solution sol;
    string S = "abcdddeeeeaabbbcd";
    vector<vector<int>> res = sol.largeGroupPositions(S);

    for(auto v : res){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}