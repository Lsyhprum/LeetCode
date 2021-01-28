#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // 保存每个人的名字和邮箱地址
        vector<std::pair<string, unordered_set<string>>> continer;
        // 邮箱索引
        unordered_map<string, int> mp; 

        for(vector<string> account : accounts) {
            string name = account[0];
            bool flag = false;
            int pos = -1;
            
            unordered_set<string> s;
            for(int i = 1; i < account.size(); i ++) {
                s.insert(account[i]);
                if(mp.count(account[i]) != 0) {
                    flag = true;
                    pos = mp[account[i]];
                }
            }
            
            if(flag) {
                continer[pos].second.insert(s.begin(), s.end());
            } else {
                continer.emplace_back(name, s);
                pos = continer.size() - 1;
            }

            for(auto i : s) {
                mp[i] = pos;
            }
        }

        vector<vector<string>> res;

        for(auto e : continer) {
            vector<string> tmp;
            for(auto i : e.second) {
                tmp.push_back(i);
            }
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), e.first);
            res.push_back(tmp);
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> accounts = {
        {"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
        {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
        {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
        {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
        {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
    
    vector<vector<string>> res = sol.accountsMerge(accounts);
    for(auto iter : res) {
        for(auto iter2 : iter) {
            std::cout << iter2 << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}