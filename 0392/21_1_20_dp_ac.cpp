#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        t.insert(t.begin(), ' ');

        vector<vector<int>> dp(t.size(), vector<int>(26, 0));
        for(int i = 0; i < 26; i ++) {
            int nextPos = -1;
            for(int pos = t.size() - 1; pos >= 0; pos --) {
                dp[pos][i] = nextPos;

                if(t[pos] == 'a' + i) {
                    nextPos = pos;
                }
            }
        }

        int index = 0;
        for(int i = 0; i < s.size(); i ++) {
            index = dp[index][s[i] - 'a'];
            if(index == -1) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    std::cout << sol.isSubsequence("axc", "afdsbfdsfc") << std::endl;
    return 0;
}