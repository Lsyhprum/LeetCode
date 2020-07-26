# include <iostream>
# include <math.h>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;      // wa: 未考虑负数情况

        bool ugly[65535] = {};          // wa: 打表数组长度太小
        int prime[3] = {2, 3, 5};
        ugly[1] = true;
        ugly[2] = true;
        ugly[3] = true;
        ugly[5] = true;

        for(int i = 1; i < 65535; i ++){
            if(ugly[i]){
                for(int j = 0; j < 3; j ++){
                    int val = prime[j];
                    while(i * val < 65535){
                        ugly[i * val] = true;

                        val *= prime[j];
                    }
                }
            }
        } 

        return ugly[num];
    }
};

int main(){

    Solution sol;

    cout << sol.isUgly(65535) << endl;
    // for(int i = 1; i < 100; i ++){
    //     cout << i << " " << sol.isUgly(i) << endl;
    // }

    return 0;
}