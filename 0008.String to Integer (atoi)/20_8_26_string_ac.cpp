#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string num = "";
        string symbol = "";
        for(char c : str){
            if(c == ' '){
                if(num.empty() && symbol.empty()) 
                    continue;
                else 
                    break;
            }else if(c == '+' || c == '-'){
                if(num.empty() && symbol.empty())
                    symbol += c;
                else
                    break;
            }else if(c >= '0' && c <= '9'){
                num += c;
            }else{
                break;
            }
        }
        if(num.empty())
            return 0;
        
        //cout << num << endl;
        long long tmp = 0;
        int pos = 0;
        while(tmp <= INT_MAX && tmp >= INT_MIN && pos < num.size()){
            tmp *= 10;
            tmp += (num[pos] - '0');
            
            //cout << tmp << endl;
            pos ++;
        }
        
        if(symbol == "-")
            tmp *= -1;

        if(tmp > INT_MAX) return INT_MAX;
        if(tmp < INT_MIN) return INT_MIN;
        
        return tmp;
    }
};

int main(){
    Solution sol;

    cout << sol.myAtoi("-2 12.5");
    return 0;
}