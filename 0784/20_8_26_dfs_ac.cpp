#include <iostream>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string cur = "";

        function<void(int)> dfs = [&](int i) {
            if(i == S.size()){
                res.push_back(cur);
                return;
            }

            cur += S[i];
            dfs(i + 1);
            cur.pop_back();

            if(S[i] >= 'a' && S[i] <= 'z'){
                cur += (S[i] - 'a' + 'A');
                dfs(i + 1);
                cur.pop_back();
            }

            if(S[i] >= 'A' && S[i] <= 'Z'){
                cur += (S[i] - 'A' + 'a');
                dfs(i + 1);
                cur.pop_back();
            }
        };

        dfs(0);

        return res;
    }
};

int main(){
    Solution sol;

    for(string s : sol.letterCasePermutation("abC")){
        cout << s << endl;
    }
    return 0;
}