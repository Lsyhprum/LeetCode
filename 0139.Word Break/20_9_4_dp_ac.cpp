#include <iostream>
#include <vector>
#include <cstring>s
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string, bool> set;

        for(string s : wordDict)
            set.insert(s);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for(int i = 1; i <= s.size(); i ++){
            for(int j = 0; j < i; j ++){
                if(dp[j] && set.find(s.substr(j, i - j)) != set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main(){

    return 0;
}