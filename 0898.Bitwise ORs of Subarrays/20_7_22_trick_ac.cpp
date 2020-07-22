# include <iostream>
# include <vector>
# include <unordered_set>

using namespace std;

// Time complexity: O(32n)
// Space complexity: O(32n)
// Running time: TLE (83 / 83 test cases passed.)
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& A) {
//        unordered_set<int> ans;
//        unordered_set<int> cur;
       
//        for(int a : A){
//            unordered_set<int> nxt;
//            nxt.insert(a);
//            for(int b : cur){
//                nxt.insert(a | b);
//            }
//            cur.swap(nxt);
//            ans.insert(begin(cur), end(cur));
//        }

//        return ans.size();
//     }
// };

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
       vector<int> res;

       int left = 0, right;

       for(int a : A){
           right = res.size();
           res.push_back(a);
           for(int i = left; i < right; i ++){
               if(res.back() != (res[i] | a)){
                   res.push_back(res[i] | a);
               }
           }
           left = right;
       }
    
       unordered_set<int> test(res.begin(), res.end());
       return test.size();;
    }
};

int main(){

    Solution sol;

    vector<int> test = {1, 1, 4};

    cout << sol.subarrayBitwiseORs(test) << endl;

    return 0;
}