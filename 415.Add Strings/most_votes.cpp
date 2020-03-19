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
};

int main(){
    Solution sol;

    cout << sol.addStrings("99999999999999999999999999999999999999999999999", "1") << endl;
    return 0;
}