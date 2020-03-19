# include <iostream>
# include <algorithm>
# include <vector>
# include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        vector<int> res(n + m, 0);

        for(int j = m - 1; j >= 0; j --){
            for(int i = n - 1; i >= 0; i --){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;       
            }
        }

        int k = 0;
        while(k < n + m - 1 && res[k] == 0) k ++;

        string ans;

        for(int i = k; i < n + m; i ++){
            ans += (res[i] + '0');
        }

        return ans;
    }
};

int main(){ 

    Solution sol;

    cout << sol.multiply("19", "999999999999999999999999999999") << endl;

    return 0;   
}