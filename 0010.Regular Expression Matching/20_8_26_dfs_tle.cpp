#include <iostream>

using namespace std;

// 超时
class Solution {
public:
    bool isMatch(string s, string p) {
        // dfs + backtracking

        string cur = "";
        p += '@';
        return dfs(s, p, 1, cur);
    }

    bool dfs(string &s, string &p, int pos, string &cur){
        if(cur.size() > s.size()) return false;

        if(pos == p.size()){
            //cout << cur << endl;
            bool flag = true;
            for(int i = 0; i < s.size(); i ++){
                if(s[i] != cur[i] && cur[i] != '.'){
                    flag = false;
                    break;
                }
            }
            return flag;
        }

        // cout << p[pos-1] << " " <<  p[pos] << endl;
        
        if(p[pos-1] == '*'){
            // if(p[pos] == '@')
            //     return false;
            // *.
            // *a
            // 对当前无影响, 指令推到下一个
            return dfs(s, p, pos + 1, cur);
        }else{
            if(p[pos] == '*'){
                //cout  << cur << endl;
                // .*
                // a*
                
                // 选择推入cur
                cur.push_back(p[pos-1]);
                if(dfs(s, p, pos, cur))
                    return true;
                cur.pop_back();

                // 放弃
                return dfs(s, p, pos + 1, cur);
            }else if(p[pos] == '@'){
                // .@
                // a@
                cur.push_back(p[pos-1]);
                if(dfs(s, p, pos + 1, cur))
                    return true;
                cur.pop_back();

                return false;
            }else{
                // ..
                // a.
                // .a
                // aa
                cur.push_back(p[pos-1]);
                if(dfs(s, p, pos + 1, cur))
                    return true;
                cur.pop_back();

                return false;
            }
        }
        
    }
};

int main(){
    Solution sol;

    cout << sol.isMatch( "ccababcccbbaaabbaa", "ab*.a*.*.*a*a*.*a*") ;
    return 0;
}