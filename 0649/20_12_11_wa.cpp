#include <iostream>

using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {

        int radiant = 0, dire = 0;
        bool rflag = false, dflag = false;

        for(int round = 0; round < 2; round ++) {
            for(int i = 0; i < (round == 0 ? senate.size() : senate.size() - 1); i ++) {
                if(senate[i] == 'R') {
                    if(dire != 0) {
                        dire --;
                    } else {
                        radiant ++;
                        rflag = true;
                        dflag = false;
                    }
                } else {
                    if(radiant != 0) {
                        radiant --;
                    }else{
                        dire ++;
                        dflag = true;
                        rflag = false;
                    }
                }
            }
        }

        if(radiant == 0 && dire == 0) {
            return rflag ? "Dire" : "Radiant";
        }

        return radiant == 0 ? "Dire" : "Radiant";
    }
};


int main() {
    Solution sol;

    std::cout << sol.predictPartyVictory("RDD") << std::endl;
    return 0;
}