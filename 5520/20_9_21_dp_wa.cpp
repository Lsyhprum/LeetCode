#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        vector<string> v;
        unordered_set<string> c;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 0;

        for(int i = 1; i < s.size() + 1; i ++) {
            string tmp = "";
            tmp += s[i - 1];

            if(c.find(tmp) == c.end()) {
                dp[i] = dp[i-1] + 1;
            } else {
                int j = i - 1;
                while(c.find(tmp) != c.end()) {
                    tmp = s[--j] + tmp;
                    c.erase(v.back());
                    v.pop_back();
                }
                dp[i] = dp[j] + 1;
            }
            v.push_back(tmp);
            c.insert(tmp);
        }

        for(int i = 0; i < dp.size(); i ++) {
            cout << dp[i] << endl;
        }

        return dp[s.size()];
    }
};

int main() {
    Solution sol;
    cout << sol.maxUniqueSplit("fcmfacp");

    return 0;
}