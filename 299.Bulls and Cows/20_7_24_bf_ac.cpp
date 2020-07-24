# include <iostream>
# include <unordered_map>
# include <sstream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<int, int> map_s;  // 多余 guess
        unordered_map<int, int> map_g;  // 多余 secret

        for(int i = 0; i < secret.size(); i ++){
            if(secret[i] == guess[i])
                bulls ++;
            else{
                if(map_s[guess[i]] == 0){
                    map_s[guess[i]] ++;
                    cout << "in" << guess[i] << endl;
                }
                else{
                    map_g[guess[i]] --;
                    cows ++;
                    cout << guess[i] << endl;
                }

                if(map_g[secret[i]] == 0){
                    cout << "in" << secret[i] << endl;
                    map_g[secret[i]] ++;
                }
                else{
                    map_s[secret[i]] --;
                    cows ++;
                    cout << secret[i] << endl;
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
    cout << sol.getHint("1807", "7810") << endl;
    return 0;
}