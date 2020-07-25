# include <iostream>
# include <vector>
# include <algorithm>
# include <sstream>

using namespace std;

// Time complexity : O(n)
// Space complexity : O(n)
// Running Time : 16ms (beats 99.80%)
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> table_s(10, 0);
        vector<int> table_g(10, 0);

        for(int i = 0; i < secret.size(); i ++){
            if(secret[i] == guess[i])
                bulls ++;
            else{
                table_s[secret[i] - '0'] ++;
                table_g[guess[i] - '0'] ++;
            }
        }

        for(int i = 0; i < 10; i ++){
            cows += min(table_g[i], table_s[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

int main(){
    Solution sol;
    cout << sol.getHint("1234", "0111") << endl;
    return 0;
}