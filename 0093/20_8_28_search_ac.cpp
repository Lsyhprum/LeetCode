#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
            
        int len = s.size();
        if(len < 4 || len > 12) return ans;

        vector<string> cur;
        dfs(s, 4, 0, cur, ans); 
        return ans;
    }

private:

    bool legal(int last_num, int last_len){
        if(last_num * 1 <= last_len && last_num * 3 >= last_len) return true;
        return false;
    }

    void dfs(const string &s, int level, int start, vector<string> &cur, vector<string> &ans){
        // for(auto s : cur){
        //     cout << s << endl;
        // }
        if(level == 0 && start == s.size()){
            string s ;

            for(const auto& num : cur){
                s += num;
                s += '.';
            }
            s.pop_back();
            ans.push_back(s);
        }

        if(s[start] == '0'){
            cur.push_back("0");
            dfs(s, level - 1, start + 1, cur, ans);
            cur.pop_back();
        }else{
            // 一位
            // 0 1 2 3 4 5 6
            int remain_len = s.size() - start - 1;

            if(legal(level-1, remain_len)){
                string tmp = "";
                tmp += s[start];
                cur.push_back(tmp);
                dfs(s, level- 1, start + 1, cur, ans);
                cur.pop_back();
            }

            // 两位
            remain_len = s.size() - start - 2;

            if(legal(level-1, remain_len)){
                string tmp = "";
                tmp += s[start]; tmp += s[start+1];
                cur.push_back(tmp);
                dfs(s, level - 1, start + 2, cur, ans);
                cur.pop_back();
            }

            // 三位
            remain_len = s.size() - start - 3;
            if(legal(level-1, remain_len)){
                int num = (s[start] - '0') * 100 + (s[start + 1] - '0') * 10 + (s[start + 2] - '0');

                if(num > 255) return;
                string tmp = "";
                tmp += s[start]; tmp += s[start+1]; tmp += s[start+2];
                cur.push_back(tmp);
                dfs(s, level - 1, start + 3, cur, ans);
                cur.pop_back();
            }
        }

    }

};

int main(){

    Solution sol;

    for(auto s : sol.restoreIpAddresses("25525511135")){
        cout << s << endl;
    }

    return 0;
}