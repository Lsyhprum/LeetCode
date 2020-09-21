#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        vector<string> v;
        unordered_set<string> set;
        int max = 0;

        dfs(s, v, set, 0, max);

        for(int i = 0; i < v.size(); i ++)
            cout << v[i] << endl;

        return max;
    }

    void dfs(string s, vector<string> &v, unordered_set<string> &c, int pos, int &max) {
        if(pos == s.size()) {
            max = max > v.size() ? max : v.size();
            return ;
        }
                
        string tmp = "";
        for(int i = pos; i < s.size(); i ++) {
            tmp += s[i];

            if(c.find(tmp) == c.end()) {
                v.push_back(tmp);
                c.insert(tmp);
                dfs(s, v, c, i + 1, max);
                c.erase(tmp);
                v.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;

    cout << sol.maxUniqueSplit("abbb");
    return 0;
}