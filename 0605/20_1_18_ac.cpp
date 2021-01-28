#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool flag = false;
        for(int i = 0; i < flowerbed.size(); i ++) {
            if(!flowerbed[i] && !flag && (i == flowerbed.size() - 1 || !flowerbed[i + 1])) {
                flowerbed[i] = 1;
                n --;
            }
            
            flag = false;
            if(flowerbed[i] == 1) {
                flag = true;
            }
        }

        for(int i = 0; i < flowerbed.size(); i ++)
            std::cout << flowerbed[i] << std::endl;

        if(n <= 0) return true;
        else return false;
    }
};

int main() {
    vector<int> v = {0, 0, 0};
    Solution sol;

    std::cout << sol.canPlaceFlowers(v, 1);
    return 0;
}