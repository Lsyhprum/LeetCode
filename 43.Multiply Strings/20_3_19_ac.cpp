# include <iostream>
# include <algorithm>
# include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;

        int carry = 0, sum;
        string ans;

        while(i >= 0 || j >= 0 || carry){
            sum = 0;
            if(i >= 0) {sum += (num1[i] - '0'); i --;}
            if(j >= 0) {sum += (num2[j] - '0'); j --;}
            sum += carry;

            carry = sum / 10;
            sum %= 10;

            ans += to_string(sum);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";                          // num1 == "0" 未考虑

        string ans = "0";
        int carry = 0;

        for(int j = num2.size() - 1; j >= 0; j --){
            string tmp;                                      // 易错：暂存记得每次循环前清空
            for(int i = num1.size() - 1; i >= 0; i --){
                tmp += to_string((((num1[i] - '0') * (num2[j] - '0') + carry) % 10));
                carry = ((num1[i] - '0') * (num2[j] - '0') + carry) / 10;
            }
            while(carry){
                tmp += to_string((carry % 10));
                carry /= 10;
            }

            reverse(tmp.begin(), tmp.end());

            for(int k = 1; k < num2.size() - j; k ++){
                tmp += "0";
            }

            ans = addStrings(ans, tmp);
        }

        return ans;
    }
};

int main(){ 

    Solution sol;

    cout << sol.multiply("1234567890", "1000000000000000000000000000000000000") << endl;

    return 0;   
}