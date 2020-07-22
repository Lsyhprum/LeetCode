# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(1)
// Running time: TLE (72 / 83 test cases passed.)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res;
        for(int i = 0; i < A.size(); i ++){
            int tmp = A[i];
            for(int j = i; j < A.size(); j ++){
                tmp |= A[j];
                if(res.find(tmp) == res.end()){
                    res.insert(tmp);
                }
            }
        }
        return res.size();
    }
};

int main(){
    Solution sol = Solution();
    vector<int> val = {1, 2, 4};
    cout << sol.subarrayBitwiseORs(val) << endl;
    return 0;
}