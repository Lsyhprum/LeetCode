# include <iostream>
# include <algorithm>
# include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;

        int tmp = 0, a, b;
        string ans;
        string s;           // string 是否需要初始化

        while(i >= 0 || j >= 0){
            if(i >= 0){
                a = num1[i] - '0';
            }else{
                a = 0;
            }

            if(j >= 0){
                b = num2[j] - '0';
            }else{
                b = 0;
            }

            s.push_back('0' + (a + b + tmp) % 10);         // string 添加新元素 push_back  s[i] = x 错误
            tmp = (a + b + tmp) / 10;

            i --;
            j --;
        }

        while(tmp){
            s.push_back('0' + tmp % 10);
            tmp /= 10;
        }

        for(int i = s.length() - 1; i >= 0; i --){
            ans.push_back(s[i]);
        }

        return ans;
    }
};

int main(){
    Solution sol;

    cout << sol.addStrings("99999999999999999999999999999999999999999999999", "1") << endl;
    return 0;
}