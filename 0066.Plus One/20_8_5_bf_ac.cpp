#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 0;
        for(int i = digits.size() - 1; i >= 0; i --){
            if(i == digits.size() - 1){
                flag = (digits[i] + 1) / 10;
                digits[i] = (digits[i] + 1) % 10;
            }else{
                int tmp = digits[i] + flag;
                digits[i] = tmp % 10;
                flag = tmp / 10;
            }
        }
        if(flag){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main(){

    Solution sol;
    vector<int> digits = {1, 0};
    vector<int> res = sol.plusOne(digits);
    for(int i = 0; i < res.size(); i ++){
        cout << res[i];
    }

    return 0;

}