#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int num = envelopes.size();

        if(num < 2) return num;

        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] < b[1];

            return a[0] < b[0];
        });

        vector<int> dp(envelopes.size(), 1);

        int result = 1;

        for(int i = 0; i < envelopes.size(); i ++) {
            for(int j = 0; j < i; j ++) {
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};

int main() {

    Solution sol;

    vector<vector<int>> envelopes = {{1, 1}, {2, 2}, {2, 3}, {4, 4}};
    std::cout << sol.maxEnvelopes(envelopes);
    return 0;
}