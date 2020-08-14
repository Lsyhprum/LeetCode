#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];

        string res = "";

        long len = strs[0].size();
        for(string s : strs)
            len = min(len , (long)s.size());

        for(int i = 0; i < len; i ++){      // 遍历字符串位置
            bool flag = true;
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j ++){   // 遍历字符串列表
                if(strs[j][i] != c){
                    //cout << strs[j][i] << endl;
                    flag = false;
                    break;
                }
            }

            if(flag == true){
                res += c;
            }else{
                break;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"flower", "flawer"};
    cout << sol.longestCommonPrefix(strs);
    return 0;
}