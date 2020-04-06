# include <iostream>
# include <math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = binaryPow(x, abs(n));
        return n >= 0 ? res : (1.0f / res);
    }

private:
    double binaryPow(double x, long long n){
        if(n == 0) return 1;

        if(n & 1){
            return myPow(x, n - 1) * x;
        }else{
            double val = myPow(x, n / 2);
            return val * val;
        }
    }
};

int main(){
    Solution sol;
    cout << sol.myPow(2.1000, -100) ;
    return 0;
}