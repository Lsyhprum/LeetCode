# include <iostream>
# include <unordered_map>
# include <sstream>

using namespace std;

// Time complexity : O(n)
// Space complexity : O(n)
// Running Time : 16ms (beats 31.47%)
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<int, int> map_s;  // 多余 secret
        unordered_map<int, int> map_g;  // 多余 guess

        for(int i = 0; i < secret.size(); i ++){
            if(secret[i] == guess[i])
                bulls ++;
            else{
                if(map_s[guess[i]] == 0){
                    map_g[guess[i]] ++;
                }else{
                    map_s[guess[i]] --;
                    cows ++;
                }

                if(map_g[secret[i]] == 0){
                    map_s[secret[i]] ++;
                }else{
                    map_g[secret[i]] --;
                    cows ++;
                }

            }
        }
        ostringstream ss;
        ss << bulls << "A" << cows << "B";
        return ss.str();
    }
};

int main(){
    Solution sol;
    cout << sol.getHint("1234", "0111") << endl;
    return 0;
}