#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int type = 0;
        dfs(amount, coins, type, 0, 0);

        return type;
    }

    void dfs(int amount, const vector<int> &coins, int &type, int cur, int pos) {
        if(cur == amount) type += 1;
        if(cur > amount) return;

        for(int i = pos; i < coins.size(); i ++) {
            if((long long) cur + coins[i] >= INT_MAX) return;

            dfs(amount, coins, type, cur + coins[i], i);
        }
    }   
};

int main() {
    Solution sol;

    vector<int> v = {1, INT_MAX};
    cout << sol.change(2, v);
    return 0;
}