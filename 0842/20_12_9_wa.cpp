#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;

        if(S.size() < 3) return res;

        vector<string> tmp;
        if(backtrack(S, 0, tmp)) {
            //std::cout << "wtf" << tmp.size() << std::endl;
            for(string s : tmp) {
                int val = str2int(s);
                //std::cout << val << std::endl;
                res.push_back(val);
            }
            
        }

        return res;
    }

    bool backtrack(string S, int start, vector<string> &tmp) {
        // if(!tmp.empty()) {
        //     for(string ss : tmp)
        //         std::cout << ss << " ";
        //     std::cout << std::endl;
        // }

        // 字符串拆分完成
        if(start >= S.size() && tmp.size() >= 3) return true;

        string val = "";
        for(int pos = start; pos < S.size(); pos ++) {
            val.push_back(S[pos]);

            if(S[start] == '0' && pos > start) {
                return false;
            }

            // 验证正确性
            if(tmp.size() >= 2) {
                int val1 = str2int(tmp[tmp.size() - 2]);
                int val2 = str2int(tmp[tmp.size() - 1]);
                int result = str2int(val);
                //std::cout << "val1 " << val1 << std::endl;
                //std::cout << "val1 " << val2 << std::endl;
                //std::cout << val << std::endl;
                //std::cout << "result " << result << std::endl;

                if(val1 + val2 == result) {
                    tmp.push_back(val);
                    if(backtrack(S, pos + 1, tmp)) {
                        return true;
                    }else{
                        tmp.pop_back();
                        return false;
                    }
                } else if (val1 + val2 < result) {
                    return false;
                } else {
                    continue;
                }
            } else {
                tmp.push_back(val);
                if(backtrack(S, pos + 1, tmp)) {
                    return true;
                }else{
                    tmp.pop_back();
                }
            }
        }

        return false;
    }

    int str2int(string s) {
        int val = 0;
        for(char c : s) {
            val = val * 10 + c - '0';
        }
        return val;
    }

    string ll2str(long long val) {
        string s = "";
        while(val) {
            char c = val % 10 + '0';
            s.push_back(c);
            val /= 10;
        }
        return s;
    }
};

int main() {
    Solution sol;

    vector<int> v = sol.splitIntoFibonacci("214748364721474836422147483641");

    for(int i : v) {
        std::cout << i << std::endl;
    }

    return 0;
}