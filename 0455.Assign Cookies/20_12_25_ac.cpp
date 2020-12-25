#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// time complexity : O(nlogn)
// space complexity : O(n)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int num = 0;
        int g_index = 0;

        for(int i = 0; i < s.size() && g_index < g.size(); i ++) {
            if(s[i] >= g[g_index]) {
                num += 1;
                g_index += 1;
            }
        }
        return num;
    }
};

int main() {
    Solution sol;
    vector<int> g = {2, 3, 3, 1, 6, 7};
    vector<int> s = {1, 2, 3, 10, 2};
    std::cout << sol.findContentChildren(g, s);
    return 0;
}