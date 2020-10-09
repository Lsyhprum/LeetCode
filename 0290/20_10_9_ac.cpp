#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        // 记录pattern
        unordered_map<char, vector<int>> map;
        for(int i = 0; i < pattern.size(); i ++) {
            map[pattern[i]].push_back(i);
        }

        // 拆分s
        vector<string> v;
        string tmp = "";
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] != ' ') {
                tmp += s[i];
            } else {
                v.push_back(tmp);
                tmp = "";
            }
        }
        if(!tmp.empty()) v.push_back(tmp);

        // 比较长度
        if(v.size() != pattern.size()) return false;

        // 记录word,保持不同
        unordered_set<string> set;
        for(auto iter : map) {
            string str = v[iter.second[0]];
            if(set.find(str) == set.end()) {
                set.insert(str);
            }else{
                return false;
            }

            for(int i = 0; i < iter.second.size(); i ++) {
                if(v[iter.second[i]] != str) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    std::cout << sol.wordPattern("a", "a");
    return 0;
}