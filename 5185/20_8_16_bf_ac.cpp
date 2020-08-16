#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int num = 0;
        for(int i = 0; i < arr.size(); i ++){
            if(arr[i] % 2 != 0){
                num ++;
                if(num == 3)
                    return true;
            }else{
                num = 0;
            }
        }

        return false;
    }
};