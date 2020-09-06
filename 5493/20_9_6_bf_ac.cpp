#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n = arr.size();
        if(n < 2) return 0;

        int pre = 1;
        for(int i = 1; i < n && arr[i] >= arr[i-1]; i ++){
            pre ++;
        }
        
        int suf = 1;
        for(int i = n - 2; i >= 0 && arr[i] <= arr[i + 1]; i --){
            suf ++;
        }

        if(pre == n-1) return 0;

        //cout << pre << " " << suf << endl;

        int ans = min(n - pre, n - suf);

        for(int l = 0; l < pre; l ++){
            for(int r = n - suf; r < n; r ++){
                if(arr[r] < arr[l]) continue;
                 cout << r << " " << l << endl;
                int len = r - l - 1;
                ans = min(len, ans);
                break;
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,2,3,10,4,2,3,5};
    cout << sol.findLengthOfShortestSubarray(v);
    return 0;
}