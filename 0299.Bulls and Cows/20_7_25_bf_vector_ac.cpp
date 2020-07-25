# include <iostream>
# include <vector>
# include <sstream>

using namespace std;

// Time complexity : O(n)
// Space complexity : O(n)
// Running Time : 16ms (beats 83.46%)
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> s(10, 0); // 多余secret
        vector<int> g(10, 0); // 多余guess

        for(int i = 0; i < secret.size(); i ++){
            if(secret[i] == guess[i]){
                bulls ++;
            }else{
                if(s[guess[i] - '0'] != 0){
                    s[guess[i] - '0'] --;
                    cows ++;
                }else{
                    g[guess[i] - '0'] ++;
                }

                if(g[secret[i] - '0'] != 0){
                    g[secret[i] - '0'] --;
                    cows ++;
                }else{
                    s[secret[i] - '0'] ++;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(){
    Solution sol;
    cout << sol.getHint("1123", "0111") << endl;
    return 0;
}