#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<pair<int, int>> s;

        for(int i = 0; i < T.size(); i ++) {
            while(!s.empty() && s.top().first < T[i]) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push(pair<int, int>(T[i], i));
        }

        while(!s.empty()) {
            res[s.top().second] = 0;
            s.pop();
        }

        return res;

    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v1 = sol.dailyTemperatures(v);

    for(int i = 0; i < v1.size(); i ++) {
        cout << v1[i] << endl;
    }

    return 0;
}