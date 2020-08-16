#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> dp;
    int recursion(int n){
        if(n == 0)
            return 0;
        if(dp.find(n) != dp.end()) return dp[n];
        dp[n] = n;
        if(n % 2 == 0){
            dp[n] = min(dp[n], recursion(n - (n/2)) + 1);
        }
        if(n % 3 == 0){
            dp[n] = min(dp[n], recursion(n - (2*(n/3))) + 1);
        }
        if((n-1)%2 == 0 || (n-1)%3 == 0){
            dp[n] = min(dp[n], recursion(n-1) + 1);
        }
        if((n-2)%3 == 0){
            dp[n] = min(dp[n], recursion(n-2) + 2);
        }
        return dp[n];
    }

    int minDays(int n) {
        return recursion(n);
    }
};

int main(){

    return 0;
}