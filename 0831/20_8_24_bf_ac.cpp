#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string maskPII(string S) {
        // "name1@name2.name3"
        // 1~3-10

        string res;
        if(S[0] >= '0' && S[0] <= '9' || S[0] == '+' || S[0] == '-' || S[0] == '(' || S[0] == ')' || S[0] == ' ') { // 电话号码
            vector<char> num;
            for(char c : S){
                if(c >= '0' && c <= '9'){
                    num.push_back(c);
                }
            }

            if(num.size() > 10) {  // 国际号
                res += "+";

                for(int i = 0; i < num.size() - 10; i ++){
                    res += "*";
                }
                res += "-";
            }
            res.append("***-***-");

            for(int i = 4; i > 0; i --){
                res += (num[num.size() - i]);
            }
        } else {  // 邮箱

            res += transform(S[0]);
            res.append("*****");
            
            int i = 1;
            while(S[i] != '@'){
                i ++;
            }

            res += transform(S[i-1]);
            res += '@';

            for(int j = i + 1; j < S.size(); j ++)
                res += transform(S[j]);

        }
        return res;
    }

private:
    char transform(char c){
        if(c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
        return c;
    }
};

int main(){
    Solution sol;
    cout << sol.maskPII("name1@name2.name3");
    return 0;
}